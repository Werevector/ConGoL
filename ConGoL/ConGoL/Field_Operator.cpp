#include "Field_Operator.h"


void Field_Operator::next_Gen(Field& l_Field){

	std::vector<std::vector<int>> s_Field = l_Field.get_sumField();

	for (int x = 0; x < l_Field.get_FieldSize_X()-1; x++){
		for (int y = 0; y < l_Field.get_FieldSize_Y() - 1; y++){

			if (s_Field[x][y] < 2){
				l_Field.Set_State_DEAD(x,y);
			}
			else if (s_Field[x][y] > 3){
				l_Field.Set_State_DEAD(x,y);
			}
			else if (s_Field[x][y] == 3){
				l_Field.Set_State_LIVE(x,y);
			}
		}
	}


}