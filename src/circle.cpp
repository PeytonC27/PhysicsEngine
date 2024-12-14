#include "../include/circle.h"
#include <cmath>
#include <iostream>

Circle::Circle(Vector center, float radius, bool useGravity) : Shape(center, useGravity), radius(radius) {
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
}
