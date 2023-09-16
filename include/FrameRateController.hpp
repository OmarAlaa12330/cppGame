#pragma once

#include <SDL_stdinc.h>

class FrameRateController {
public:
    explicit FrameRateController(int targetFPS);

    void delayIfNeeded() const;
    inline void setFrameStart(Uint32 currentFrame){mFrameStart = currentFrame;}

private:
    int mTargetFPS{};
    Uint32 mFrameStart{};
    Uint32 mFrameDelay{};
};


