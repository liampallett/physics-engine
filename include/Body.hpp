//
// Created by Liam Pallett on 16/03/2026.
//

#ifndef PHYSICS_ENGINE_BODY_HPP
#define PHYSICS_ENGINE_BODY_HPP

#include <string>
#include <vector>
#include "Vector2.hpp"

constexpr double G = 6.674e-11;

struct Body {
    std::string name;
    double mass;
    double radius;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;

    Body(const std::string& name, double mass, double radius, const Vector2& position, const Vector2& velocity)
        : name(name), mass(mass), radius(radius), position(position), velocity(velocity), acceleration({0,0}) {}

    // Velocity Verlet Calculations
    void updatePosition(double dt) {
        position += velocity * dt + acceleration * 0.5 * pow(dt, 2);
    }

    void updateVelocity(double dt, const Vector2& previousAcceleration) {
        velocity += (previousAcceleration + acceleration) * 0.5 * dt;
    }

    void updateAcceleration(const std::vector<Body>& bodies) {
        Vector2 acc = {0, 0};
        for (const Body& body : bodies) {
            if (&body == this) continue;
            Vector2 directionVector =  (body.position - position);
            double r = directionVector.length();
            double accelerationMagnitude = (G * body.mass)/pow(r, 2);
            acc += directionVector.normalise() * accelerationMagnitude;
        }
        acceleration = acc;
    }
};

#endif //PHYSICS_ENGINE_BODY_HPP