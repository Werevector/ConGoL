#pragma once
#include <vector>;

class Field{

public:

	Field();

	//Innitiate Field Default, a set size, or Premade 
	void Innitiate_Field_DEF();
	void Innitiate_Field_SET(int x_Size, int y_Size);
	void Innitiate_Field_PRE(std::vector<std::vector<int>>);

	//Return reference to Field
	std::vector<std::vector<int>>& get_FieldRef();

	//Set a single space(x,y) to DEAD or LIVE
	void Set_State_DEAD(int x, int y);
	void Set_State_LIVE(int x, int y);




private:

	int const DEFAULT_SIZE = 100;
	std::vector<std::vector<int>> l_Field;


};