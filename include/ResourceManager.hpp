#pragma once

#include <unordered_map>
#include <string>
#include <SDL.h>
#include "RenderWindow.hpp"

/**
 * @brief A resource manager for loading, storing, and managing SDL textures.
 *
 * The ResourceManager class is responsible for loading and caching SDL textures
 * and provides methods to access and release textures efficiently.
 */
class ResourceManager {
public:
    explicit ResourceManager(RenderWindow& window): mWindow(window){};
    SDL_Texture* loadTexture(const std::string&);
    void releaseTexture(SDL_Texture* texture);
    void cleanUp();

private:
    RenderWindow& mWindow; /**< reference of RenderWindow to access SDL_Render* within it*/
    std::unordered_map<std::string, SDL_Texture*> mTextureCache{};
};

