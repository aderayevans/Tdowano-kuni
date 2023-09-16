#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP

#include <iostream>

struct Vector2f
{
    Vector2f() : x(0.0f), y(0.0f) {}

    Vector2f(float p_x, float p_y) : x(p_x), y(p_y) {}

    Vector2f& Add(const Vector2f& p_vector);
    Vector2f& Subtract(const Vector2f& p_vector);
    Vector2f& Multiply(const Vector2f& p_vector);
    Vector2f& Divide(const Vector2f& p_vector);

    Vector2f& operator+=(const Vector2f& p_vector);
    Vector2f& operator-=(const Vector2f& p_vector);
    Vector2f& operator*=(const Vector2f& p_vector);
    Vector2f& operator/=(const Vector2f& p_vector);

    friend Vector2f& operator+(Vector2f& p_v1, const Vector2f& p_v2);
    friend Vector2f& operator-(Vector2f& p_v1, const Vector2f& p_v2);
    friend Vector2f& operator*(Vector2f& p_v1, const Vector2f& p_v2);
    friend Vector2f& operator/(Vector2f& p_v1, const Vector2f& p_v2);

    friend std::ostream& operator<<(std::ostream& p_stream, const Vector2f& p_vector);

    float x, y;
};

#endif // VECTOR2F_HPP
