#include "Field_Operator.h"


void Field_Operator::next_Gen(Field& l_Field){
	int sum = 0;
	for (int x = 0; x < l_Field.get_FieldSize_X-1; x++){
		for (int y = 0; y < l_Field.get_FieldSize_Y - 1; y++){
			sum = l_Field.get_NeighborSum(x,y);

			if (sum < 2){
				l_Field.Set_State_DEAD(x,y);
			}
			else if (sum > 3){
				l_Field.Set_State_DEAD(x,y);
			}
			else if(sum == 3){
				l_Field.Set_State_LIVE(x,y);
			}
		}
	}


}