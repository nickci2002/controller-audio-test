#include <iostream>
#include <memory>

#include <SDL3/SDL.h>
#include <SDL3/SDL_gamepad.h>
#include <SDL3/SDL_audio.h>
#include <SDL3/SDL_properties.h>
#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_hidapi.h>


int main(int argc, char* args[]) {
    
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS4, "1");
    
    // Initialize gamepad subsystem
    if (!SDL_Init(SDL_INIT_GAMEPAD | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO)) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    auto device_info = SDL_hid_enumerate(0, 0);
	if (!device_info) {
		std::cerr << "No HID devices found!" << std::endl;
		SDL_Quit();
		return 1;
	}
	for (auto current = device_info; current != nullptr; current = current->next) {
		std::cout << "HID devices found: 0x" << std::hex << current->vendor_id
				  << "|0x" << current->product_id << std::dec << std::endl;
	}
	

    // SDL Cleanup
	SDL_hid_free_enumeration(device_info);
    SDL_Quit();

    return 0;
}