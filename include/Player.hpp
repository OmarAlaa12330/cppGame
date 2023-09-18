#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"
#include "Renderable.hpp"

class Player : public Renderable{
public:
    Player(Vector2f position, SDL_Texture *tex);
    Player(Vector2f position, int width, int height, SDL_Texture *tex);

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

private:
    float mStep{2.0f};
};


