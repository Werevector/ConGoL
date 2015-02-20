#include "Cell.h"

bool operator==(Cell const& p1, Cell const& p2)
{
	return p1.x_Pos == p2.x_Pos && p1.y_Pos == p2.y_Pos;
}

std::size_t hash_value(Cell const& p) {
	std::size_t seed = 0;
	boost::hash_combine(seed, p.x_Pos);
	boost::hash_combine(seed, p.y_Pos);
	return seed;
}