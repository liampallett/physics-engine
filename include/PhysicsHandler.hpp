//
// Created by Liam Pallett on 16/03/2026.
//

#ifndef PHYSICS_ENGINE_PHYSICSHANDLER_HPP
#define PHYSICS_ENGINE_PHYSICSHANDLER_HPP

#include <vector>
#include "Body.hpp"
#include "Vector2.hpp"

struct PhysicsHandler {
    std::vector<Body> bodies;

    void addBody(const Body& body) {
        bodies.push_back(body);
    }

    void step(double dt) {
        std::vector<Vector2> previousAccelerations;
        previousAccelerations.reserve(bodies.size());

        for (Body& body : bodies) {
            previousAccelerations.push_back(body.acceleration);
            body.updatePosition(dt);
        }

        for (Body& body : bodies) {
            body.updateAcceleration(bodies);
        }

        for (int i = 0; i < bodies.size(); i++) {
            bodies[i].updateVelocity(dt, previousAccelerations[i]);
        }
    }

    void simulate(double dt, int steps) {
        for (int i = 0; i < steps; i++) {
            step(dt);
        }
    }
};

#endif //PHYSICS_ENGINE_PHYSICSHANDLER_HPP