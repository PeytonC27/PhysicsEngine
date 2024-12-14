#include <iostream>
#include "SDL2/SDL.h"
#include "../include/framework.h"

int main(int argc, char* argv[])
{
    int fps = 120;
    double msPerFrame = (1000.0/fps);
    double delta = 1.0/fps;

    double gravity = -9.81;

    int height = 400;
    int width = 800;

    Framework fw(height, width);

    std::cout << delta << std::endl;

    Shape* mainCharacter = fw.createCircle(Vector(100, 300), 25);
    fw.createSquare(Vector(300, 375), 25);
    
    fw.drawObjects();

    SDL_Event event;
    const Uint8* state = SDL_GetKeyboardState(nullptr);;

    while (!(event.type == SDL_QUIT)) {
        SDL_Delay(msPerFrame);          // setting a delay

        fw.clear();                     // clear the last frame
        fw.calculatePhysics(gravity, delta);
        fw.drawObjects();               // drawing all objects
        fw.collisionCorrection();

        std::cout << mainCharacter->center.x << " " << mainCharacter->center.y << std::endl;

        if (state[SDL_SCANCODE_D])
            mainCharacter->rb.velocity = Vector(2, mainCharacter->rb.velocity.y);
        else if (state[SDL_SCANCODE_A])
            mainCharacter->rb.velocity = Vector(-2, mainCharacter->rb.velocity.y);
        else
            mainCharacter->rb.velocity = Vector(0, mainCharacter->rb.velocity.y);

        if (state[SDL_SCANCODE_SPACE] && fw.objectIsGrounded(mainCharacter)) {
            std::cout << "jump" << std::endl;
            mainCharacter->rb.velocity = Vector(mainCharacter->rb.velocity.x, -5);
            mainCharacter->rb.jumped = false;
        }

        SDL_PollEvent(&event);          // catching event
    }

    return 0;
}