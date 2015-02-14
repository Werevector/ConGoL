#include "Field.h"

Field::Field(){

}

//Innitiate Field Default (full 0)
void Field::Initiate_Field_DEF(){

	l_Field = std::vector<std::vector<int>>(DEFAULT_SIZE, std::vector<int>(DEFAULT_SIZE));
	f_xSize = DEFAULT_SIZE;
	f_ySize = DEFAULT_SIZE;
	
	//TESTING
	//l_Field[50][49] = 1;
	//l_Field[50][50] = 1;
	//l_Field[50][51] = 1;

	//l_Field[50][70] = 1;
	//l_Field[51][71] = 1;

	l_Field[1][3] = 1;
	l_Field[1][4] = 1;
	l_Field[1][5] = 1;

	/*l_Field[66][20] = 1;
	l_Field[66][21] = 1;
	l_Field[66][22] = 1;*/

}

//Innitiate Field with a set x,y size (0)
void Field::Initiate_Field_SET(int x_Size, int y_Size){

	l_Field = std::vector<std::vector<int>>(x_Size, std::vector<int>(y_Size));
	f_xSize = x_Size;
	f_ySize = y_Size;
}

//Innitiate Field with Premade
void Field::Initiate_Field_PRE(std::vector<std::vector<int>> pre_Vec){
	l_Field = pre_Vec;
	f_xSize = l_Field.size();
	f_ySize = l_Field[0].size();
}

void Field::Set_State_DEAD(int x, int y){
	l_Field[x][y] = 0;
}

void Field::Set_State_LIVE(int x, int y){
	l_Field[x][y] = 1;
}

int Field::get_NeighborSum(int x, int y){
	int result = 0;

	//WARNING, GRUESOME CODE AHEAD, DO NOT ATTEMPT READING. 
	
	//Left neighbor Row
	if (x != 0){
		if (y != 0){ result += l_Field[x - 1][y - 1]; }
		result += l_Field[x - 1][y];
		if (y != f_ySize){ result += l_Field[x - 1][y + 1]; }
	}

	// Middle neighbor Row
	if (y != 0){ result += l_Field[x][y - 1]; }
	if (y != f_ySize-1){ result += l_Field[x][y + 1]; }

	//Right neighbor Row
	if (x != f_xSize-1){
		if (y != 0){ result += l_Field[x + 1][y - 1]; }
		result += l_Field[x + 1][y];
		if (y != f_ySize){ result += l_Field[x + 1][y + 1]; }
	}

	return result;
}

std::vector<std::vector<int>> Field::get_sumField(){
	std::vector<std::vector<int>> s_Field;
	s_Field = std::vector<std::vector<int>>(f_xSize, std::vector<int>(f_ySize));


	for (int x = 0; x < f_xSize-1; x++){
		for (int y = 0; y < f_ySize-1; y++){
			s_Field[x][y] = get_NeighborSum(x,y);
		}
	}

	return s_Field;

}


int Field::get_FieldState(int x, int y){
	return l_Field[x][y];
}

void Field::set_Field(std::vector<std::vector<int>> new_Field){
	l_Field.operator=(new_Field);
}

std::vector<std::vector<int>>& Field::get_FieldRef(){
	return l_Field;
}

int Field::get_FieldSize_X(){
	return f_xSize;
}

int Field::get_FieldSize_Y(){
	return f_ySize;
}