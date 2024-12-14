#include "../include/circle.h"
#include <cmath>
#include <iostream>

Circle::Circle(Vector center, float radius, bool useGravity, bool hasBounds) : Shape(center, useGravity, hasBounds), radius(radius) {
}

Circle::~Circle(){
    
}

void Circle::draw(SDL_Renderer* renderer) {

    for (int x = center.x - radius; x <= center.x + radius; x++) {
        for (int y = center.y - radius; y <= center.y + radius; y++) {
            double inCircle = (std::pow(center.y - y, 2) + std::pow(center.x - x, 2)) <= std::pow(radius, 2);
            if (inCircle) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }

    SDL_RenderDrawPoint(renderer, center.x, center.y + radius + 1);
}

bool Circle::isGrounded(float windowHeight) {

    if (center.y + radius + 1 >= windowHeight) {
        return true;
    }
    return false;
}

bool Circle::inBounds(Vector check) {
    bool inSquareRegion = check.x >= center.x - radius && check.x <= center.x + radius
                        && check.y >= center.y - radius && check.y <= center.y + radius;
                        
    return inSquareRegion && ::pow(center.y - check.y, 2) + std::pow(center.x - check.x, 2) <= std::pow(radius, 2);
}

std::vector<Vector> Circle::getBoundChecks() {
    std::vector<Vector> bounds(4);

    bounds[0] = Vector(center.x - radius, center.y);
    bounds[1] = Vector(center.x, center.y - radius);
    bounds[2] = Vector(center.x, center.y + radius);
    bounds[3] = Vector(center.x + radius, center.y);

    return bounds;
}

Vector Circle::getGroundCheckVector() {
    return Vector(center.x, center.y + radius + 1);
}