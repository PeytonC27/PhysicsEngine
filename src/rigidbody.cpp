#include "../include/rigidbody.h"
#include <iostream>

void RigidBody::applyGravity(double gravityConstant, double delta) {
    
    velocity += Vector::Down * (gravityConstant * delta);

}