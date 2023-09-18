#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Renderable.hpp"

RenderWindow::RenderWindow(const char *title, int width, int height){
    mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (mWindow == nullptr){
        std::cerr << "WINDOW FAILED TO INIT. ERROR:\n" << SDL_GetError() << std::endl;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void RenderWindow::clear() {
    SDL_RenderClear(mRenderer);
}

void RenderWindow::render(Renderable& entity) {
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;

    int scale = 4;  //to scale image
    SDL_Rect dst;
    dst.x = entity.getPos().x * scale;
    dst.y = entity.getPos().y * scale;
    dst.w = entity.getCurrentFrame().w * scale;
    dst.h = entity.getCurrentFrame().h * scale;

    SDL_RenderCopy(mRenderer, entity.getTex(), &src, &dst);
}

void RenderWindow::display() {
    SDL_RenderPresent(mRenderer);
}

int RenderWindow::getRefreshRate() {
    int displayIndex{SDL_GetWindowDisplayIndex(mWindow)};

    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}

void RenderWindow::cleanUp() {
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
}

