#pragma once
#include <iostream>
#include "SDL.h"
#include "SimLoop.h"
#include "Field.h"
#include "Field_Renderer.h"
#include "GameTimer.h"
#include <dos.h>
#include "L16_FParser.h"
#include <chrono>
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
	L16_Parser::Load_Field(m_Field, "LF106//pulsar.life");

	m_FRenderer.Init();

	m_Timer.Reset();

	int frame_Cap = 30;
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

		if (currentKeyStates[SDL_SCANCODE_G]){
			m_FRenderer.switch_Grid_State();
		}
		
		m_FRenderer.Render_All(m_Field);
		
		auto t_start = std::chrono::high_resolution_clock::now();
		m_Loop.runOnce(m_Field);
		auto t_end = std::chrono::high_resolution_clock::now();

		double time = std::chrono::duration<double, std::milli>(t_end - t_start).count();

		std::cout << "NextGenTime: " << time << "\n";
		
		total_FrameTime = 1000 / frame_Cap;
		if (m_Timer.DeltaTime() < total_FrameTime){
			SDL_Delay(total_FrameTime - m_Timer.DeltaTime());
		}

		
		

		m_Timer.Tick();
	}

	m_Loop.StopSim();
	m_FRenderer.~Field_Renderer();
	close();


	return 0;

}//main

void close()
{

	//Quit SDL subsystems
	SDL_Quit();
}