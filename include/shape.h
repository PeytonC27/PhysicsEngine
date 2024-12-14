#pragma once

#include "SDL2/SDL.h"
#include "rigidbody.h"
#include <iostream>
#include "vector.h"
#include <cmath>
#include <vector>


class Shape {
public:
    Shape(const Vector center, bool useGravity=true, bool hasBounds=false) : center(center), useGravity(useGravity), hasBounds(hasBounds) {}
    virtual ~Shape() {}


    virtual bool inBounds(Vector check) = 0;
    virtual std::vector<Vector> getBoundChecks() = 0;
    virtual void draw(SDL_Renderer* renderer) = 0;

    virtual bool isGrounded(float windowHeight) = 0;
    virtual Vector getGroundCheckVector() = 0;

    virtual void physicsTick(float gravity, float delta, float windowHeight) {

        // the y coordinates are flipped in an image, so the ground level is the height of the 
        
        // ground check
        if (isUnderGround(center.y, windowHeight) && rb.velocity.y > 0) {
            center.y = windowHeight;
            rb.velocity.y = 0;
        }
        
        if (useGravity)
            rb.applyGravity(gravity, delta);
        center += rb.velocity;

        if (isUnderGround(center.y, windowHeight) && isGrounded(windowHeight))
            std::cout << "both" << std::endl;
        else if (isUnderGround(center.y, windowHeight))
            std::cout << "under" << std::endl;
        else if (isGrounded(windowHeight))
            std::cout << "grounded" << std::endl;
            

        if (!isGrounded(windowHeight))
            rb.jumped = false;

        //std::cout << center.x << " " << center.y << " " << std::endl;
    }

    Vector center;
    RigidBody rb;
    bool useGravity;
    bool hasBounds;
    bool groundedOverride = false;
    bool grounded;

private:
    bool isUnderGround(double yCoord, double windowHeight) {
        return yCoord >= windowHeight;       
    }
};