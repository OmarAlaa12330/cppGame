#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"

/**
 * Renderable class that can inherited to display textures on a window
 */
class Renderable{
public:
    Renderable(Vector2f position, SDL_Texture* tex);
    Renderable(Vector2f position, int width, int height, SDL_Texture* tex);

    //Getters
    inline Vector2f& getPos() {return mPos;}
    inline SDL_Texture* getTex() {return mTexture;}
    inline SDL_Rect getCurrentFrame() {return mCurrentFrame;}


protected:
    Vector2f mPos{};
    SDL_Rect mCurrentFrame{};
    SDL_Texture* mTexture{nullptr};
};