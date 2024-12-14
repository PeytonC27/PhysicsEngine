#include "../include/square.h"

Square::Square(Vector center, float sideLength, bool useGravity, bool hasBounds) : Shape(center, useGravity, hasBounds), sideLength(sideLength) {

}

Square::~Square() {
    
}

void Square::draw(SDL_Renderer *renderer) {
    for (int x = center.x - sideLength; x <= center.x + sideLength; x++) {
        for (int y = center.y - sideLength; y <= center.y + sideLength; y++) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

bool Square::isGrounded(float windowHeight) {
    Vector toCheck(center.x, center.y + sideLength + 1);

    if (toCheck.y + sideLength + 1 >= windowHeight) {
        return true;
    }
    return false;
}

bool Square::inBounds(Vector check) {
    return check.x >= center.x - sideLength && check.x <= center.x + sideLength
        && check.y >= center.y - sideLength && check.y <= center.y + sideLength;
}

std::vector<Vector> Square::getBoundChecks() {
    std::vector<Vector> bounds(8);

    bounds[0] = Vector(center.x - sideLength, center.y - sideLength);
    bounds[1] = Vector(center.x - sideLength, center.y);
    bounds[2] = Vector(center.x - sideLength, center.y + sideLength);

    bounds[3] = Vector(center.x, center.y - sideLength);
    bounds[4] = Vector(center.x, center.y + sideLength);

    bounds[5] = Vector(center.x + sideLength, center.y - sideLength);
    bounds[6] = Vector(center.x + sideLength, center.y);
    bounds[7] = Vector(center.x + sideLength, center.y + sideLength);

    return bounds;
}

Vector Square::getGroundCheckVector() {
    return Vector(center.x, center.y + sideLength + 1);
}