#pragma once
#include <boost/unordered_map.hpp>
struct Cell{

	int x_Pos;
	int y_Pos;
	int state;

};

bool operator==(Cell const& p1, Cell const& p2);

std::size_t hash_value(Cell const& p);