#include "Field.h"

//Innitiate Field Default (full 0)
void Field::Innitiate_Field_DEF(){

	l_Field = std::vector<std::vector<int>>(DEFAULT_SIZE, std::vector<int>(DEFAULT_SIZE));

}

//Innitiate Field with a set x,y size (0)
void Field::Innitiate_Field_SET(int x_Size, int y_Size){

	l_Field = std::vector<std::vector<int>>(x_Size, std::vector<int>(y_Size));

}

//Innitiate Field with Premade
void Field::Innitiate_Field_PRE(std::vector<std::vector<int>> pre_Vec){
	l_Field = pre_Vec;
}

void Field::Set_State_DEAD(int x, int y){
	l_Field[x][y] = 0;
}

void Field::Set_State_LIVE(int x, int y){
	l_Field[x][y] = 1;
}

std::vector<std::vector<int>>& Field::get_FieldRef(){
	return l_Field;
}