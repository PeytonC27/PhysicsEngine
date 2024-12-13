#pragma once

#include "SDL2/SDL.h"
#include "vector.h"
#include "shape.h"
#include <vector>

class Framework {
public:
    Framework(int height, int width);
    ~Framework();

    void createCircle(Vector coords, int radius);
    void calculatePhysics(double gravity, double delta);
    void drawObjects();
    void clear();

private:
    int height;
    int width;
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL; 
    std::vector<Shape*> objects;
};