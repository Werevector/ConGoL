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

void Field::Set_State_DEAD(int x, int y){
	l_Field[x][y] = 0;
}

void Field::Set_State_LIVE(int x, int y){
	l_Field[x][y] = 1;
}

int Field::get_NeighborSum(int x, int y){

	int result = 0;

	int new_x;
	int new_y;

	Cell cell;


	for (int fx = 0; fx < relative_a.size() - 1; fx++){

		new_x = x + relative_a[fx][0];
		new_y = y + relative_a[fx][1];

		if (new_x > 0 && new_x < f_xSize && new_y > 0 && new_y < f_ySize){
			
			cell.x_Pos = new_x;
			cell.y_Pos = new_y;
			
			C_Map[cell] 
		}



	}
}

void Field::calc_Neighbour_Sums(){
	
	
	BOOST_FOREACH(cellMap::value_type i, C_Map) {
		C_Map[i.first] = get_NeighborSum(i.first.x_Pos, i.first.y_Pos);
	}

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
	
	int new_x;
	int new_y;

	for (int fx = 0; fx < relative_a.size() - 1; fx++){
		
		new_x = x + relative_a[fx][0];
		new_y = y + relative_a[fx][1];

		if (new_x > 0 && new_x < f_xSize && new_y > 0 && new_y < f_ySize){
			n_cell.x_Pos = x + relative_a[fx][0];
			n_cell.y_Pos = y + relative_a[fx][1];
			map.emplace(n_cell, 0);
		}
		
		

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