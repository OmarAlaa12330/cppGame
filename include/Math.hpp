#pragma once

#include <iostream>

struct Vector2f{
    float x, y;

    Vector2f(): x(0.0f), y(0.0f){}
    Vector2f(float xPos, float yPos): x(xPos), y(yPos){}

    void print() const{
        std::cout << "(" << x << ", " << y << ")\n";
    }


};