#include "Renderable.hpp"

#include <SDL.h>
#include <SDL_image.h>

Renderable::Renderable(Vector2f position, SDL_Texture *tex)
        : mPos(position), mTexture(tex){
    mCurrentFrame = {0,0,16,16};
}

Renderable::Renderable(Vector2f position, int width, int height, SDL_Texture *tex)
        : mPos(position), mTexture(tex){
    mCurrentFrame = {0,0,width,height};
}
