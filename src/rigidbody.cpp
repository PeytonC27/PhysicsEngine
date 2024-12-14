#include "../include/rigidbody.h"
#include <iostream>

void RigidBody::applyGravity(float gravityConstant, float delta) {
    
    velocity += Vector::Down * (gravityConstant * delta);

}

void RigidBody::addVelocity(Vector velocity) {
    this->velocity += velocity;
}