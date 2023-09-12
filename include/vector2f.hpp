#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP

struct Vector2f
{
    Vector2f() : x(0.0f), y(0.0f) {}

    Vector2f(float p_x, float p_y) : x(p_x), y(p_y) {}

    float x, y;
};

#endif // VECTOR2F_HPP