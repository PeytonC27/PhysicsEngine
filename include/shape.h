#pragma once

#include "SDL2/SDL.h"
#include "rigidbody.h"
#include <iostream>
#include "vector.h"
#include <cmath>


class Shape {
public:
    Shape(const Vector center, bool useGravity) : center(center), useGravity(useGravity) {}
    virtual ~Shape() {}
    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void physicsTick(double gravity, double delta, double windowHeight) {
        // the y coordinates are flipped in an image, so the ground level is the height of the 
        float yPos = std::round(center.y);

        // if the object is at the ground, bounce it back up
        if (isUnderGround(yPos, windowHeight) && !groundedOverride && std::abs(rb.velocity.y) > 0.005) {
            groundedOverride = true;
            rb.velocity = rb.velocity * -0.9;
        }

        // grounded check
        if (yPos >= windowHeight && rb.velocity.y > 0) {
            center.y = windowHeight;
            rb.velocity = Vector(0, 0);
        }
        
        rb.applyGravity(gravity, delta);
        center += rb.velocity;

        if (!isUnderGround(yPos, windowHeight)) 
            groundedOverride = false;

        //std::cout << center.x << " " << center.y << " " << std::endl;
    }

    Vector center;
    RigidBody rb;
    bool useGravity;
    bool groundedOverride = false;

private:
    bool isUnderGround(double yCoord, double windowHeight) {
        return yCoord >= windowHeight;       
    }
};