#pragma once

#include "shape.h"
#include "vector.h"

class Circle : public Shape {
public:
    Circle(Vector center, float radius, bool useGravity=true, bool hasBounds=false);
    ~Circle();
    void draw(SDL_Renderer *renderer) override;
    bool isGrounded(float windowHeight) override;
    bool inBounds(Vector check) override;
    std::vector<Vector> getBoundChecks() override;
    Vector getGroundCheckVector() override;

    int radius;
};