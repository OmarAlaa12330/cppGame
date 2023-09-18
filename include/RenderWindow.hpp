#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Renderable.hpp"

class RenderWindow{
public:
    RenderWindow(const char* title, int width, int height);
    void clear();
    void render(Renderable& entity);
    void display();
    int getRefreshRate();
    void cleanUp();

    //getters
    inline SDL_Window* getWindow() {return mWindow;}
    inline SDL_Renderer* getRenderer() {return mRenderer;}

private:
    SDL_Window* mWindow{nullptr};
    SDL_Renderer* mRenderer{nullptr};
};