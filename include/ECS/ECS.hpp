#ifndef ECS_HPP
#define ECS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <array>
#include <bitset>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public: 
    Entity* entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual ~Component() {}
};

class Entity
{
private:
    bool m_active = true;
    std::vector<std::unique_ptr<Component>> m_components;

    ComponentArray m_componentArray;
    ComponentBitset m_componentBitset;
public:
    void update()
    {
        for (auto & c : m_components) c->update();
    }
    void draw() 
    {
        for (auto & c : m_components) c->draw();
    }
    inline bool isActive() const { return m_active; }
    inline void destroy()  { m_active = false; }

    template <typename T> bool hasComponent() const
    {
        return m_componentBitset[getComponentTypeID<T>()];
    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        m_components.emplace_back(std::move(uPtr));

        m_componentArray[getComponentTypeID<T>()] = c;
        m_componentBitset[getComponentTypeID<T>()] = true;

        c->init();
        return *c;
    }

    template <typename T> T& getComponent() const
    {
        auto ptr(m_componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager
{
private:
    std::vector<std::unique_ptr<Entity>> m_entities;

public:
    void update()
    {
        for (auto& e : m_entities) e->update();
    }

    void draw()
    {
        for (auto& e : m_entities) e->draw();
    }

    void refresh()
    {
        m_entities.erase(std::remove_if(std::begin(m_entities), std::end(m_entities),
            [](const std::unique_ptr<Entity> &mEntity)
        {
            return !mEntity->isActive();
        }),
            std::end(m_entities));
    }

    Entity& addEntity()
    {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{ e };
        m_entities.emplace_back(std::move(uPtr));
        return *e;
    }
};

#endif // ECS_HPP