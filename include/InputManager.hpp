#pragma once

#include <SDL.h>
#include <unordered_map>

/**
 * @brief A simple input manager for handling keyboard input and quit requests.
 */
class InputManager {
public:
    InputManager(): mQuitRequested(false){};

    /**
     * @brief Updates the internal state of the input manager.
     *
     * This method should be called once per frame to update the input state.
     */
    void update();

    /**
    * @brief Checks if a specific key is currently pressed.
    *
    * @param key The SDL_KeyCode of the key to check.
    * @return True if the key is currently pressed, false otherwise.
    */
    bool isKeyPressed(SDL_KeyCode key) const;

    /**
     * @brief Checks if a quit request has been made (e.g., the user closed the window).
     *
     * @return True if a quit request has been made, false otherwise.
     */
    bool shouldQuit() const;

private:
    std::unordered_map<SDL_Keycode, bool> mKeyStates{};
    bool mQuitRequested{};
};


