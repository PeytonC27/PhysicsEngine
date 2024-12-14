#pragma once

#include "shape.h"
#include "vector.h"

class Square : public Shape {
public:
    Square(Vector center, float sideLength, bool useGravity=true, bool hasBounds=false);
    ~Square();
    void draw(SDL_Renderer *renderer) override;
    bool isGrounded(float windowHeight) override;
    bool inBounds(Vector check) override;
    std::vector<Vector> getBoundChecks() override;
    Vector getGroundCheckVector() override;

    int sideLength;
};