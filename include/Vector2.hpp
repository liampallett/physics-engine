//
// Created by Liam Pallett on 16/02/2026.
//

#ifndef NEWTONIAN_ORBIT_MECHANICS_VECTOR2_HPP
#define NEWTONIAN_ORBIT_MECHANICS_VECTOR2_HPP
#include <cmath>

struct Vector2 {
    double x;
    double y;

    Vector2 operator+(Vector2 other) const {
        return Vector2{x + other.x, y + other.y};
    }

    Vector2 operator-(Vector2 other) const {
        return Vector2{x - other.x, y - other.y};
    }

    Vector2 operator*(double other) const {
        return Vector2{x * other, y * other};
    }

    double length() const {
        return std::sqrt(x*x + y*y);
    }

    double lengthSquared() const {
        return x*x + y*y;
    }

    Vector2 normalise() const {
        double length = this.length();
        if (length == 0) return {0,0};

        return {this.x / length, this.y / length};
    }
};

#endif //NEWTONIAN_ORBIT_MECHANICS_VECTOR2_HPP