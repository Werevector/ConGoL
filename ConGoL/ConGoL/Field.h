#pragma once
#include <vector>
#include <list>
#include "Cell.h"

class Field{

public:

	Field();

	//Innitiate Field Default, a set size, or Premade 
	void Initiate_Field_DEF();
	void Initiate_Field_SET(int x_Size, int y_Size);
	void Initiate_Field_PRE(std::vector<std::vector<int>>);

	//Return reference to Field
	std::vector<std::vector<int>>& get_FieldRef();

	//Set a single space(x,y) to DEAD or LIVE
	void Set_State_DEAD(int x, int y);
	void Set_State_LIVE(int x, int y);

	//Calculates the sum of adjecent spaces
	int get_NeighborSum(int x, int y);

	int get_FieldSize_X();
	int get_FieldSize_Y();
	int get_FieldState(int x, int y);

	std::list<Cell> get_pCell_List();

	void next_Gen();

	std::vector<std::vector<int>> get_sumField();

	void set_Field(std::vector<std::vector<int>>);


private:

	int const DEFAULT_SIZE = 100;
	
	std::vector<std::vector<int>> l_Field;

	std::list<Cell> C_List;

	int f_xSize;
	int f_ySize;

	

};