#pragma once
#include "SDL.h"
#include "Field.h"
#include <iostream>

class Field_Renderer{


public:

	Field_Renderer();
	~Field_Renderer();

	void Render_FieldGrid(int rows, int coll);
	void Render_FieldRect(int xPos, int yPos);
	void Render_Field(Field& r_Field);
	void Render_All(Field& r_Field);
	void Init();
	void switch_Grid_State();


private:

	float f_resolution;
	SDL_Renderer* f_Renderer;
	SDL_Window* f_Window;

	bool GRID_STATE;

	int const SCREEN_WIDTH = 800;
	int const SCREEN_HEIGHT = 800;

	SDL_Rect l_Rect;

};