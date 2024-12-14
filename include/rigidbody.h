#pragma once

#include "vector.h"

class RigidBody {
public:
    void applyGravity(float gravityConstant, float delta);
    void addVelocity(Vector velocity);

    Vector velocity;

};