#include "shape.h"
#include "vector.h"

class Circle : public Shape {
public:
    Circle(Vector center, int radius, bool isRigidBody=false);
    ~Circle();
    void draw(SDL_Renderer *renderer) override;

    int radius;
};