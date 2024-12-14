#pragma once

class Vector {
public:
    Vector(float x, float y);
    Vector();
    ~Vector();

    Vector normalized();
    float magnitude();

    Vector operator+(const Vector& other) const;
    Vector& operator+=(const Vector& other);

    Vector operator*(float scalar) const;
    Vector operator*=(float scalar);

    friend Vector operator*(float scalar, const Vector& vector);

    float x = 0;
    float y = 0;

    static Vector Down;
    static Vector Up;
    static Vector Left;
    static Vector Right;
};