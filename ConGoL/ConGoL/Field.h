#pragma once
#include <vector>
#include <list>
#include "Cell.h"
#include <boost/unordered_map.hpp>
#include <boost/foreach.hpp>

typedef boost::unordered_map<Cell, int> cellMap;

class Field{

public:

	Field();

	//Innitiate Field Default, a set size, or Premade 
	void Initiate_Field_DEF();
	void Initiate_Field_SET(int x_Size, int y_Size);
	void Initiate_Field_PRE(std::vector<std::vector<int>>);

	//Return reference to Field
	//std::vector<std::vector<int>>& get_FieldRef();

	//Set a single space(x,y) to DEAD or LIVE
	void Set_State_DEAD(int x, int y);
	void Set_State_LIVE(int x, int y);

	//Calculates the sum of adjecent spaces
	int get_NeighborSum(int x, int y);

	int get_FieldSize_X();
	int get_FieldSize_Y();
	int get_FieldState(int x, int y);

	cellMap get_pCell_Map();

	void next_Gen();

	void calc_Neighbour_Sums();

	void set_Field(std::vector<std::vector<int>>);

	void add_Cell_wPadd(cellMap &map, int x, int y);
	void add_Cell_wPadd(int x, int y);


private:

	int const DEFAULT_SIZE = 10;
	
	std::vector<std::vector<int>> l_Field;

	//Adds Cell with padding to changeList
	//void C_AddCell(Cell n_Cell, std::list<Cell>& n_list);

	cellMap C_Map;

	int f_xSize;
	int f_ySize;

	std::vector<std::vector<int>> relative_a;

	

};