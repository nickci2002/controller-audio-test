#include <iostream>
#include <SDL3/SDL_gamepad.h>

int main(int argc, char* args[]) {
    for (int i = 0; i < SDL_GetNumAudioDrivers(); ++i) {
        const char* driverName = SDL_GetAudioDriver(i);
        if (driverName) {
            std::cout << "Audio Driver " << i << ": " << driverName << std::endl;
        } else {
            std::cerr << "Error retrieving audio driver " << i << ": " << SDL_GetError() << std::endl;
        }
    }

    return 0;
}