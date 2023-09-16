#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "FrameRateController.hpp"
#include "InputManager.hpp"
#include "ResourceManager.hpp"

void initPackages();

int main() {

    initPackages();

    //Initialise required classes
    RenderWindow window("game v1.0", 1280, 720);
    ResourceManager srcManager(window);
    FrameRateController rateController(window.getRefreshRate());
    InputManager inputManager;

    SDL_Texture* grassTexture = srcManager.loadTexture("../res/gfx/ground_grass.png");

    //Testing rendering multiple textures
    std::vector<Entity> entities = {Entity(Vector2f(0,100), grassTexture),
                                    Entity(Vector2f(30, 100), grassTexture),
                                    Entity(Vector2f(60, 100), grassTexture),
                                    Entity(Vector2f(90, 100), grassTexture),
                                    Entity(Vector2f(120, 100), grassTexture)};


    bool gameIsRunning{true};
    while (gameIsRunning){
        rateController.setFrameStart(SDL_GetTicks());

        //(1) Handle Input
        inputManager.update();
        if (inputManager.shouldQuit())
            gameIsRunning = false;


        //(2) Rendering Graphics
        window.clear();
        for (Entity& entity : entities){
            window.render(entity);
        }
        window.display();



        //(3) Frame Rate Control
        rateController.delayIfNeeded();
    }


    //Clearing buffers and exiting program
    srcManager.cleanUp();
    window.cleanUp();
    SDL_Quit();

    return 0;
}

void initPackages(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "ERROR WHILE INITIALISING SDL2: \n" << SDL_GetError() << std::endl;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL2 Initialisation Error", SDL_GetError(), nullptr);
        exit(EXIT_FAILURE);
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cerr << "ERROR WHILE INITIALISING SDL2_image:\n" << SDL_GetError() << std::endl;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL2_image Initialisation Error", SDL_GetError(), nullptr);
        exit(EXIT_FAILURE);
    }
}