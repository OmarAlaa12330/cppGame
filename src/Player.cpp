#include "Player.hpp"

#include <SDL.h>
#include <SDL_image.h>

Player::Player(Vector2f position, SDL_Texture *tex)
    : Renderable(position, tex){}

Player::Player(Vector2f position, int width, int height, SDL_Texture *tex)
    : Renderable(position, width, height, tex){}

void Player::moveRight() {
    mPos.x += mStep;
}

void Player::moveLeft() {
    mPos.x -= mStep;
}

void Player::moveUp() {
    mPos.y -= mStep;
}

void Player::moveDown() {
    mPos.y += mStep;
}