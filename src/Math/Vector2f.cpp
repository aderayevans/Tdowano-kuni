#include "Math/Vector2f.hpp"

Vector2f& Vector2f::Add(const Vector2f& p_vector)
{
    this->x += p_vector.x;
    this->y += p_vector.y;
    return *this;
}

Vector2f& Vector2f::Subtract(const Vector2f& p_vector)
{
    this->x -= p_vector.x;
    this->y -= p_vector.y;
    return *this;
}

Vector2f& Vector2f::Multiply(const Vector2f& p_vector)
{
    this->x *= p_vector.x;
    this->y *= p_vector.y;
    return *this;
}

Vector2f& Vector2f::Divide(const Vector2f& p_vector)
{
    this->x /= p_vector.x;
    this->y /= p_vector.y;
    return *this;
}

Vector2f& Vector2f::operator+=(const Vector2f& p_vector)
{
    return this->Add(p_vector);
}

Vector2f& Vector2f::operator-=(const Vector2f& p_vector)
{
    return this->Subtract(p_vector);
}

Vector2f& Vector2f::operator*=(const Vector2f& p_vector)
{
    return this->Multiply(p_vector);
}

Vector2f& Vector2f::operator/=(const Vector2f& p_vector)
{
    return this->Divide(p_vector);
}

Vector2f& operator+(Vector2f& p_v1, const Vector2f& p_v2)
{
    return p_v1.Add(p_v2);
}

Vector2f& operator-(Vector2f& p_v1, const Vector2f& p_v2)
{
    return p_v1.Subtract(p_v2);
}

Vector2f& operator*(Vector2f& p_v1, const Vector2f& p_v2)
{
    return p_v1.Multiply(p_v2);
}

Vector2f& operator/(Vector2f& p_v1, const Vector2f& p_v2)
{
    return p_v1.Divide(p_v2);
}

std::ostream& operator<<(std::ostream& p_stream, const Vector2f& p_vector)
{
    p_stream << "(" << p_vector.x << ", " << p_vector.y << ")";
    return p_stream;
}