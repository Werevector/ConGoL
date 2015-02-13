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

	int get_NeighborSum(int x, int y);

	int get_FieldSize_X();
	int get_FieldSize_Y();


private:

	int const DEFAULT_SIZE = 100;
	std::vector<std::vector<int>> l_Field;

	int f_xSize;
	int f_ySize;


};