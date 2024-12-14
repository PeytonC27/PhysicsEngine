#include "../include/vector.h"
#include <cmath>

Vector::Vector(float x, float y) : x(x), y(y) {}

Vector::Vector() : x(0), y(0) {}

Vector::~Vector() {}

Vector Vector::normalized() {
    float magnitude = this->magnitude();
    return Vector(x / magnitude, y / magnitude);
}

float Vector::magnitude() {
    return std::sqrt(x * x + y * y);
}


Vector Vector::operator+(const Vector& other) const {
    return Vector(this->x + other.x, this->y + other.y);
}

Vector& Vector::operator+=(const Vector& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}


Vector Vector::operator*(float scalar) const {
    return Vector(this->x * scalar, this->y * scalar);
}

Vector Vector::operator*=(float scalar) {
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}


Vector operator*(float scalar, const Vector& vector) {
    return vector * scalar;
}


Vector Vector::Down(0, -1);
Vector Vector::Up(0, 1);
Vector Vector::Left(-1, 0);
Vector Vector::Right(1, 0);