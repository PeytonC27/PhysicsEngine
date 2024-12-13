#include "vector.h"

class RigidBody {
public:
    void applyGravity(double gravityConstant, double delta);

    Vector velocity;

};