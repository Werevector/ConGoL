#include "Field.h"

typedef boost::unordered_map<Cell, int> cellMap;

Field::Field(){
	relative_a = { 
	{ -1, -1 },
	{ -1, 0 },
	{ -1, 1 },
	{ 0, -1 },
	{ 0, 1 },
	{ 1, -1 },
	{ 1, 0 },
	{ 1, 1 }
	};
}

//Innitiate Field Default (full 0)
void Field::Initiate_Field_DEF(){

	l_Field = std::vector<std::vector<int>>(DEFAULT_SIZE, std::vector<int>(DEFAULT_SIZE));
	f_xSize = DEFAULT_SIZE;
	f_ySize = DEFAULT_SIZE;

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

void Field::calc_Neighbour_Sums(){

	//std::vector<std::vector<int>> s_Field;
	//s_Field = std::vector<std::vector<int>>(f_xSize, std::vector<int>(f_ySize));
	
	
	BOOST_FOREACH(cellMap::value_type i, C_Map) {
		C_Map[i.first] = get_NeighborSum(i.first.x_Pos, i.first.y_Pos);
	}

	//for (cellMap::iterator cell = C_Map.begin(); cell != C_Map.end(); ++cell){
	//	int x = cell->x_Pos;
	//	int y = cell->y_Pos;



	//		//cell->neighbors = get_NeighborSum(x, y);
	//		//
	//		//if (l_Field[x - 1][x - 1] != 1){ s_Field[x - 1][y - 1] = get_NeighborSum(x - 1, y - 1); }
	//		//if (l_Field[x - 1][y] != 1){ s_Field[x - 1][y] = get_NeighborSum(x - 1, y); }
	//		//if (l_Field[x - 1][y + 1] != 1){ s_Field[x - 1][y + 1] = get_NeighborSum(x - 1, y + 1); }
	//		//
	//		//if (l_Field[x][y - 1] != 1){ s_Field[x][y - 1] = get_NeighborSum(x, y - 1); }
	//		////if (l_Field[x][y] != 1){ s_Field[x][y] = get_NeighborSum(x, y); }
	//		//if (l_Field[x][y + 1] != 1){ s_Field[x][y + 1] = get_NeighborSum(x, y + 1); }
	//		//
	//		//if (l_Field[x + 1][y - 1] != 1){ s_Field[x + 1][y - 1] = get_NeighborSum(x + 1, y - 1); }
	//		//if (l_Field[x + 1][y] != 1){ s_Field[x + 1][y] = get_NeighborSum(x + 1, y); }
	//		//if (l_Field[x + 1][y + 1] != 1){ s_Field[x + 1][y + 1] = get_NeighborSum(x + 1, y + 1); }
	//}

	//return s_Field;

}

void Field::next_Gen(){

	cellMap new_CellMap;

	calc_Neighbour_Sums();


	BOOST_FOREACH(cellMap::value_type cell, C_Map) {

		if (cell.second < 2){
			Set_State_DEAD(cell.first.x_Pos, cell.first.y_Pos);
		}
		else if (cell.second > 3){
			Set_State_DEAD(cell.first.x_Pos, cell.first.y_Pos);
		}
		else if (cell.second == 3){
			Set_State_LIVE(cell.first.x_Pos, cell.first.y_Pos);

			add_Cell_wPadd(new_CellMap, cell.first.x_Pos, cell.first.y_Pos);
		}
		else{
			add_Cell_wPadd(new_CellMap, cell.first.x_Pos, cell.first.y_Pos);
		}
	}

	C_Map = new_CellMap;

}

	/*for (std::list<Cell>::const_iterator cell = C_Map.begin(); cell != C_Map.end(); ++cell){

			if (s_Field[cell->x_Pos][cell->y_Pos] < 2){
				Set_State_DEAD(cell->x_Pos, cell->y_Pos);
			}
			else if (s_Field[cell->x_Pos][cell->y_Pos] > 3){
				Set_State_DEAD(cell->x_Pos, cell->y_Pos);
			}
			else if (s_Field[cell->x_Pos][cell->y_Pos] == 3){
				Set_State_LIVE(cell->x_Pos, cell->y_Pos);

				Cell n_cell;

				n_cell.x_Pos = cell->x_Pos;
				n_cell.y_Pos = cell->y_Pos;

				new_C_List.push_back(n_cell);
			}
			else{
				
				Cell n_cell;

				n_cell.x_Pos = cell->x_Pos;
				n_cell.y_Pos = cell->y_Pos;

				new_C_List.push_back(n_cell);
			}
		}

	C_List = new_C_List;*/

void Field::add_Cell_wPadd(cellMap &map, int x, int y){
	
	Cell n_cell;

	n_cell.x_Pos = x;
	n_cell.y_Pos = y;
	n_cell.neighbors = 0;

	map.emplace(n_cell, 0);
	
	for (int fx = 0; fx < relative_a.size() - 1; fx++){
		
		n_cell.x_Pos = x + relative_a[fx][0];
		n_cell.y_Pos = y + relative_a[fx][1];
		map.emplace(n_cell, 0);
		

	}

}

void Field::add_Cell_wPadd(int x, int y){
	
	Cell n_cell;

	n_cell.x_Pos = x;
	n_cell.y_Pos = y;
	n_cell.neighbors = 0;

	C_Map.emplace(n_cell, 0);
	

	for (int fx = 0; fx < relative_a.size() - 1; fx++){


		n_cell.x_Pos = x + relative_a[fx][0];
		n_cell.y_Pos = y + relative_a[fx][1];
		C_Map.emplace(n_cell, 0);
		

	}
}

//void Field::C_AddCell(Cell n_Cell, std::list<Cell>& n_list){
//	
//	n_list.push_back(n_Cell);
//
//	if (x != 0){
//		if (y != 0){ result += l_Field[x - 1][y - 1]; }
//		result += l_Field[x - 1][y];
//		if (y != f_ySize){ result += l_Field[x - 1][y + 1]; }
//	}
//
//	// Middle neighbor Row
//	if (y != 0){ result += l_Field[x][y - 1]; }
//	if (y != f_ySize - 1){ result += l_Field[x][y + 1]; }
//
//	//Right neighbor Row
//	if (x != f_xSize - 1){
//		if (y != 0){ result += l_Field[x + 1][y - 1]; }
//		result += l_Field[x + 1][y];
//		if (y != f_ySize){ result += l_Field[x + 1][y + 1]; }
//	}
//
//}


int Field::get_FieldState(int x, int y){
	return l_Field[x][y];
}

void Field::set_Field(std::vector<std::vector<int>> new_Field){
	l_Field.operator=(new_Field);
}

//std::vector<std::vector<int>>& Field::get_FieldRef(){
//	return l_Field;
//}

int Field::get_FieldSize_X(){
	return f_xSize;
}

int Field::get_FieldSize_Y(){
	return f_ySize;
}