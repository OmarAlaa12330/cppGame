#include "InputManager.hpp"


void InputManager::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_KEYDOWN){
            mKeyStates[event.key.keysym.sym] = true;
        }
        else if (event.type == SDL_KEYUP){
            mKeyStates[event.key.keysym.sym] = false;
        }
        else if (event.type == SDL_QUIT){
            mQuitRequested = true;
        }
    }
}

bool InputManager::isKeyPressed(SDL_KeyCode key) const {
    auto state = mKeyStates.find(key);
    return state != mKeyStates.end() && state->second;
}

bool InputManager::shouldQuit() const {
    return mQuitRequested;
}
