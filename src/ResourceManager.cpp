#include "ResourceManager.hpp"

#include <SDL.h>
#include <SDL_image.h>

SDL_Texture *ResourceManager::loadTexture(const std::string& filePath) {
    if (mTextureCache.find(filePath) != mTextureCache.end())
        return mTextureCache[filePath];

    SDL_Texture* texture = IMG_LoadTexture(mWindow.getRenderer(), filePath.c_str());
    if (!texture){
        std::cout <<"Failed to load texture. Error: \n" << SDL_GetError() <<std::endl;
        return nullptr;
    }

    mTextureCache[filePath] = texture;
    return texture;
}

void ResourceManager::releaseTexture(SDL_Texture *texture) {
    for (auto it = mTextureCache.begin(); it != mTextureCache.end(); ++it) {
        if (it->second == texture) {
            SDL_DestroyTexture(it->second);
            mTextureCache.erase(it);
            break;
        }
    }
}

void ResourceManager::cleanUp() {
    for (auto& pair : mTextureCache){
        SDL_DestroyTexture(pair.second);
    }
    mTextureCache.clear();
}
