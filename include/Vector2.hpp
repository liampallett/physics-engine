//
// Created by Liam Pallett on 16/02/2026.
//

#ifndef PHYSICS_ENGINE_VECTOR2_HPP
#define PHYSICS_ENGINE_VECTOR2_HPP

#include <cmath>

struct Vector2 {
    double x;
    double y;

    [[nodiscard]] Vector2 operator+(const Vector2& other) const {
        return Vector2{x + other.x, y + other.y};
    }

    [[nodiscard]] Vector2 operator-(const Vector2& other) const {
        return Vector2{x - other.x, y - other.y};
    }

    [[nodiscard]] Vector2 operator*(const double other) const {
        return Vector2{x * other, y * other};
    }

    [[nodiscard]] Vector2 operator/(const double other) const {
        return Vector2{x / other, y / other};
    }

    Vector2& operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;

        return *this;
    }

    Vector2& operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    [[nodiscard]] double dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    [[nodiscard]] double length() const {
        return std::sqrt(x*x + y*y);
    }

    [[nodiscard]] double lengthSquared() const {
        return x*x + y*y;
    }

    [[nodiscard]] Vector2 normalise() const {
        double len = length();
        if (len == 0) return {0,0};

        return {x / len, y / len};
    }
};

#endif //PHYSICS_ENGINE_VECTOR2_HPP