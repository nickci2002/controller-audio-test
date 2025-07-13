#include <iostream>
#include <SDL3/SDL_gamepad.h>

int main(int argc, char* args[]) {
    bool hasGamepad = SDL_HasGamepad();
    if (hasGamepad) {
        std::cout << "Gamepad is available." << std::endl;
    } else {
        std::cout << "No gamepad available." << std::endl;
    }
    
    return 0;
}