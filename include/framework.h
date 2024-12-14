#pragma once

#include "SDL2/SDL.h"
#include "vector.h"
#include "shape.h"
#include "circle.h"
#include "square.h"
#include <vector>

class Framework {
public:
    Framework(int height, int width);
    ~Framework();

    Circle* createCircle(Vector coords, int radius);
    Square* createSquare(Vector coords, int sideLength);
    void calculatePhysics(float gravity, float delta);
    void addVelocity(Vector velocity);
    void drawObjects();
    void clear();
    bool objectIsGrounded(const Shape* object);

    void collisionCorrection();

private:
    int height;
    int width;
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL; 
    std::vector<Shape*> objects;
};