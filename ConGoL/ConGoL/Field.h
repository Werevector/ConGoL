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

	//Return reference to Field
	//std::vector<std::vector<int>>& get_FieldRef();

	//Set a single space(x,y) to DEAD or LIVE
	void Set_State_DEAD(int x, int y);
	void Set_State_LIVE(int x, int y);

	//Calculates the sum of adjecent spaces
	int get_NeighborSum(int x, int y);

	int get_FieldState(int x, int y);

	cellMap get_pCell_Map();

	void next_Gen();

	void calc_Neighbour_Sums();

	void add_Cell_wPadd(cellMap &map, int x, int y);
	void add_Cell_wPadd(int x, int y);


private:


	cellMap C_Map;

	int f_xSize;
	int f_ySize;

	std::vector<std::vector<int>> relative_a;

	

};