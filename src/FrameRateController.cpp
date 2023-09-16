#include <SDL.h>

#include "FrameRateController.hpp"


FrameRateController::FrameRateController(int targetFPS)
    : mTargetFPS(targetFPS){
    mFrameDelay = 1000 / targetFPS;
}

void FrameRateController::delayIfNeeded() const{
    Uint32 frameTime = SDL_GetTicks() - mFrameStart;
    if (frameTime < mFrameDelay)
        SDL_Delay(mFrameDelay - frameTime);

}
