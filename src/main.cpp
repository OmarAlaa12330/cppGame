#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "RenderWindow.hpp"
#include "Player.hpp"
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

    SDL_Texture* AlienTexture = srcManager.loadTexture("../res/gfx/Alienship.png");

    //Testing rendering multiple textures
    std::vector<Renderable> entities = {Renderable(Vector2f(0,100), AlienTexture),
                                    Renderable(Vector2f(30, 100), AlienTexture),
                                    Renderable(Vector2f(60, 100), AlienTexture),
                                    Renderable(Vector2f(90, 100), AlienTexture),
                                    Renderable(Vector2f(120, 100), AlienTexture)};

    SDL_Texture* spaceShipTexture = srcManager.loadTexture("../res/gfx/spaceship.png");
    Player player(Vector2f(100,100), spaceShipTexture);


    bool gameIsRunning{true};
    while (gameIsRunning){
        rateController.setFrameStart(SDL_GetTicks());

        //(1) Handle Input
        inputManager.update();
        if (inputManager.shouldQuit())
            gameIsRunning = false;

        if(inputManager.isKeyPressed(SDLK_LEFT))
            player.moveLeft();

        if(inputManager.isKeyPressed(SDLK_RIGHT))
            player.moveRight();

        if(inputManager.isKeyPressed(SDLK_UP))
            player.moveUp();

        if(inputManager.isKeyPressed(SDLK_DOWN))
            player.moveDown();


        //(2) Rendering Graphics
        window.clear();
        for (Renderable& entity : entities){
            window.render(entity);
        }
        window.render(player);
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