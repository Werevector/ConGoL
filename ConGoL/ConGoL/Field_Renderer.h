#include "SDL.h"

class Field_Renderer{


public:

	void Render_FieldGrid();
	void Render_FieldRect(int xPos, int yPos);

private:

	float f_resolution = 50;


};