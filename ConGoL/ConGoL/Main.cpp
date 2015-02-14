#pragma once
#include <iostream>
#include "SDL.h"
#include "SimLoop.h"
#include "Field.h"
#include "Field_Renderer.h"
#include "GameTimer.h"
#include <dos.h>

void close();


int main(int argc, char* args[]) {

	//initialize the simulator
	
	bool quit = false;
	SDL_Event event;
	Field m_Field;
	SimLoop m_Loop;
	Field_Renderer m_FRenderer;

	GameTimer m_Timer;

	//The main sim loop
	m_Field.Initiate_Field_DEF();
	m_FRenderer.Init();

	m_Timer.Reset();

	int frame_Cap = 60;
	int total_FrameTime = 1000 / frame_Cap;

	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0){
			if (event.type == SDL_QUIT){
				quit = true;
			}
		}//EventWhile

		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

		if (currentKeyStates[SDL_SCANCODE_W] && frame_Cap < 60){
			frame_Cap += 1;
		}

		if (currentKeyStates[SDL_SCANCODE_S] && frame_Cap > 1){
			frame_Cap -= 1;
		}
		
		m_FRenderer.Render_All(m_Field);
		
		//m_FRenderer.Render_FieldGrid(m_Field.get_FieldSize_X(), m_Field.get_FieldSize_Y());

		m_Loop.runOnce(m_Field);
		

		std::cout << "Time: " << m_Timer.TotalTime() << "\n";
		
		total_FrameTime = 1000 / frame_Cap;
		if (m_Timer.DeltaTime() < total_FrameTime){
			SDL_Delay(total_FrameTime - m_Timer.DeltaTime());
		}

		
		

		m_Timer.Tick();
	}

	m_Loop.StopSim();
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