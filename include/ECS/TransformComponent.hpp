#ifndef TRANSFORM_COMPONENT_HPP
#define TRANSFORM_COMPONENT_HPP

#include "Components.hpp"
#include "Math/Vector2f.hpp"

class TransformComponent : public Component
{
public:
    Vector2f position;
    Vector2f velocity;

    float speed = 3.0f;

public:
    TransformComponent()
    {
        position = Vector2f();
    }

    TransformComponent(const float& p_x, const float& p_y)
    {
        position = Vector2f(p_x, p_y);
    }

    TransformComponent(const Vector2f& p_vector)
    {
        position = Vector2f(p_vector);
    }

    void init() override
    {
        velocity = Vector2f();
    }

    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

    void setPosition(int p_x, int p_y)
    {
        position.x = p_x;
        position.y = p_y;
    }
};

#endif // TRANSFORM_COMPONENT_HPP