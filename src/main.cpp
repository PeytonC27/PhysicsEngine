#include <iostream>
#include "SDL2/SDL.h"
#include "../include/framework.h"

int main(int argc, char* argv[])
{
    int fps = 120;
    double msPerFrame = (1000.0/fps);
    double delta = 1.0/fps;

    double gravity = -9.81;

    Framework fw(400, 800);

    std::cout << delta << std::endl;

    Shape* mainCharacter = fw.createCircle(Vector(100, 300), 25);
    fw.createCircle(Vector(200, 250), 25);
    fw.createCircle(Vector(300, 200), 25);
    fw.createCircle(Vector(400, 150), 25);
    fw.createCircle(Vector(500, 100), 25);
    fw.createCircle(Vector(600, 50), 25);
    fw.createCircle(Vector(700, 0), 25);
    
    fw.drawObjects();

    SDL_Event event;
    const Uint8* state = SDL_GetKeyboardState(nullptr);;

    while (!(event.type == SDL_QUIT)) {
        SDL_Delay(msPerFrame);          // setting a delay

        fw.clear();                     // clear the last frame
        fw.calculatePhysics(gravity, delta);
        fw.drawObjects();               // drawing all objects

        if (state[SDL_SCANCODE_D])
            mainCharacter->rb.velocity = Vector(5, mainCharacter->rb.velocity.y);
        else if (state[SDL_SCANCODE_A])
            mainCharacter->rb.velocity = Vector(-5, mainCharacter->rb.velocity.y);
        else
            mainCharacter->rb.velocity = Vector(0, mainCharacter->rb.velocity.y);

        if (state[SDL_SCANCODE_SPACE])
            mainCharacter->rb.velocity = Vector(mainCharacter->rb.velocity.x, -5);

        SDL_PollEvent(&event);          // catching event
    }

    return 0;
}