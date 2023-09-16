#include "Entity.hpp"

#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(Vector2f position, SDL_Texture *tex)
    : mPos(position), mTexture(tex){
    mCurrentFrame.x = 0;
    mCurrentFrame.y = 0;
    mCurrentFrame.w = 32;
    mCurrentFrame.h = 32;
}
