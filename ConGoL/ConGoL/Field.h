#include <vector>;

class Field{

public:

	Field();

	//Innitiate Field Default or Premade 
	void Innitiate_Field();
	void Innitiate_Field_PRE();

	//Return reference to Field
	std::vector<int>& get_FieldRef();

	//Set a single space(x,y) to DEAD or LIVE
	void Set_State_DEAD(int x, int y);
	void Set_State_LIVE(int x, int y);




private:

	std::vector<std::vector<int>> l_Field;


};