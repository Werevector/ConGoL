#include "Field_Renderer.h"

Field_Renderer::Field_Renderer(){
	f_resolution = 1;
}

void Field_Renderer::Init(){
	
	f_Window = SDL_CreateWindow("ConGoL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (f_Window == NULL) { 
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError()); 
	}
	else{
		f_Renderer = SDL_CreateRenderer(f_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (f_Renderer == NULL){
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		}

	}

	l_Rect.h = f_resolution;
	l_Rect.w = f_resolution;

}

void Field_Renderer::Render_All(Field& r_Field){

	//Clear screen
	SDL_SetRenderDrawColor(f_Renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(f_Renderer);

	//Render a single field
	Render_Field(r_Field);


	Render_FieldGrid(r_Field.get_FieldSize_X(), r_Field.get_FieldSize_Y());
	

	//switch renderbuffers
	SDL_RenderPresent(f_Renderer);
}

void Field_Renderer::Render_FieldGrid(int rows, int coll){
	SDL_SetRenderDrawColor(f_Renderer, 0x30, 0x30, 0x30, 0xFF);

	for (int x = 0; x < rows; x++){
		SDL_RenderDrawLine(
			
			f_Renderer,
			x * ((int)SCREEN_WIDTH / rows) * f_resolution, 
			0, 
			
			x * ((int)SCREEN_WIDTH / rows) * f_resolution,
			SCREEN_WIDTH);
		
		for (int y = 0; y < coll; y++){

			SDL_RenderDrawLine(

				f_Renderer,
				0,
				y * ((int)SCREEN_WIDTH / coll) * f_resolution,

				SCREEN_HEIGHT,
				y * ((int)SCREEN_WIDTH / coll) * f_resolution);


		}
	}
}

void Field_Renderer::Render_Field(Field& r_Field){

	int rows = r_Field.get_FieldSize_X();
	int coll = r_Field.get_FieldSize_Y();

	l_Rect.w = (SCREEN_WIDTH / rows) * f_resolution;
	l_Rect.h = (SCREEN_HEIGHT / coll) * f_resolution;
	
	for (int x = 0; x < rows - 1; x++){
		for (int y = 0; y < coll - 1; y++){
			if (r_Field.get_FieldState(x,y) == 1){
				Render_FieldRect(x*l_Rect.w,y*l_Rect.h);
			}
		}
	}

}

void Field_Renderer::Render_FieldRect(int xPos, int yPos){
	
	l_Rect.x = xPos;
	l_Rect.y = yPos;

	SDL_SetRenderDrawColor(f_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(f_Renderer, &l_Rect);

}