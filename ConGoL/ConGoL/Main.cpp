#pragma once
#include <iostream>
#include "SDL.h"

void close();

int main(int argc, char* args[]) {

	//initialize the game
	
	bool quit = false;
	SDL_Event event;


	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0){
			if (event.type == SDL_QUIT){
				quit = true;
			}
		}//EventWhile

		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	}//GameLoop

	close();

	return 0;

}//main

void close()
{
	//Destroy window	
	/*SDL_DestroyRenderer(Graphics::gRenderer);
	SDL_DestroyWindow(Graphics::gWindow);
	Graphics::gWindow = NULL;
	Graphics::gRenderer = NULL*/;

	//Quit SDL subsystems
	SDL_Quit();
}