#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"

class RenderWindow{
public:
    RenderWindow(const char* title, int width, int height);
    SDL_Texture* loadTexture(const char* filePath);
    void clear();
    void render(Entity& entity);
    void display();
    int getRefreshRate();
    void cleanUp();

private:
    SDL_Window* mWindow{nullptr};
    SDL_Renderer* mRenderer{nullptr};
};