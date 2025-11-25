#pragma once
#include <cmath>

class Vector2
{
public:
    float x;
    float y;

    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2(const Vector2& other)
    {
        x = other.x;
        y = other.y;
    }

    Vector2& operator=(const Vector2& other)
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Vector2 operator+(const Vector2& v) const
    {
        return Vector2(x + v.x, y + v.y);
    }

    Vector2 operator-(const Vector2& v) const
    {
        return Vector2(x - v.x, y - v.y);
    }

    Vector2 operator-() const
    {
        return Vector2(-x, -y);
    }

    Vector2 operator*(float s) const
    {
        return Vector2(x * s, y * s);
    }

    float Magnitude() const
    {
        return std::sqrt(x * x + y * y);
    }

    Vector2 Normalized() const
    {
        float m = Magnitude();
        if (m == 0) return Vector2(0, 0);
        return Vector2(x / m, y / m);
    }

    void Normalize()
    {
        float m = Magnitude();
        if (m == 0) return;
        x /= m;
        y /= m;
    }

    static float Dot(const Vector2& a, const Vector2& b)
    {
        return a.x * b.x + a.y * b.y;
    }

    static float Distance(const Vector2& a, const Vector2& b)
    {
        return (a - b).Magnitude();
    }
};
