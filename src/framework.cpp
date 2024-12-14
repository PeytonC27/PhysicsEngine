#include "../include/framework.h"
#include "../include/circle.h"
#include <cmath>

Framework::Framework(int height, int width) : height(height), width(width) {
    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL as video
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);   // setting draw color
    SDL_RenderClear(renderer);                      // clear new window
    SDL_RenderPresent(renderer);                    // reflects changes done in window
}

Framework::~Framework() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    for (const auto& object : objects)
        delete object;
}

Circle* Framework::createCircle(Vector coords, int radius) {
    Circle* newCircle = new Circle(coords, radius, true, true);
    objects.push_back(newCircle);
    return newCircle;
}

Square* Framework::createSquare(Vector coords, int sideLength) {
    Square* newSquare = new Square(coords, sideLength, false, true);
    objects.push_back(newSquare);
    return newSquare;
}

void Framework::drawObjects() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (const auto& shape : objects) {
        shape->draw(renderer);
    }
    SDL_RenderPresent(renderer);
}

void Framework::calculatePhysics(float gravity, float delta) {
    for (const auto& shape : objects) {
        shape->physicsTick(gravity, delta, height-25);
    }
}

void Framework::addVelocity(Vector velocity) {
    for (const auto& shape : objects) {
        shape->rb.addVelocity(velocity);
    }
}

void Framework::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}

void Framework::collisionCorrection() {
    for (const auto& collider : objects) {                      // check all colliders
        for (const auto& collidee : objects) {                  // check all collidees

            if (collider == collidee || !collider->useGravity)
                continue;

            for (Vector bound : collidee->getBoundChecks()) {   // get all bounds of the potential collided object
                if (collider->inBounds(bound)) {                // if the collider is in a bound of the collidee...
                    Vector from = collider->rb.velocity.normalized() * -1;

                    while (collider->inBounds(bound))           // move object back out of the collider
                    {
                        std::cout << "correction" << std::endl;
                        collider->center += from;
                    }

                    collider->rb.velocity = Vector(0, 0);
                }
            }
        }
    }
}

bool Framework::objectIsGrounded(const Shape* object) {
    for (const auto& obj : objects) {
        if (obj == object) {

            if (obj->isGrounded(height)) return true;

            for (const auto& collidee : objects) {
                if (obj == collidee) continue;

                if (collidee->inBounds(obj->getGroundCheckVector())) {
                    return true;
                }
            }
        }
    }

    return false;
}