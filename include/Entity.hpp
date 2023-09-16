#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"

class Entity {
public:
    Entity(Vector2f position, SDL_Texture* tex);

    inline Vector2f& getPos() {return mPos;}
    inline SDL_Texture* getTex() {return mTexture;}
    inline SDL_Rect getCurrentFrame() {return mCurrentFrame;}


private:

    Vector2f mPos{};
    SDL_Rect mCurrentFrame{};
    SDL_Texture* mTexture{nullptr};
};


