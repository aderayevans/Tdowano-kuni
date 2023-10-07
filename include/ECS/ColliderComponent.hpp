#ifndef COLLIDER_COMPONENT_HPP
#define COLLIDER_COMPONENT_HPP

#include <string>

#include "SDL.h"

#include "ECS/Components.hpp"

class ColliderComponent : public Component
{
public:
    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;
    SpriteComponent* sprite;

public:
    ColliderComponent(std::string p_tag)
        : tag(p_tag)
    {}

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    void update() override
    {
        collider.x = transform->position.x;
        collider.y = transform->position.y;
        collider.w = sprite->getWidth() * sprite->getScale();
        collider.h = sprite->getHeight() * sprite->getScale();
    }
};

#endif // COLLIDER_COMPONENT_HPP