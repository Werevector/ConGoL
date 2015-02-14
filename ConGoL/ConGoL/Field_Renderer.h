#pragma once
#include "SDL.h"
#include "Field.h"
#include <iostream>

class Field_Renderer{


public:

	Field_Renderer();

	void Render_FieldGrid(int rows, int coll);
	void Render_FieldRect(int xPos, int yPos);
	void Render_Field(Field& r_Field);
	void Render_All(Field& r_Field);
	void Init();


private:

	float f_resolution;
	SDL_Renderer* f_Renderer;
	SDL_Window* f_Window;

	int const SCREEN_WIDTH = 1000;
	int const SCREEN_HEIGHT = 1000;

	SDL_Rect l_Rect;

};