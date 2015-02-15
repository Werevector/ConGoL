#include "L16_FParser.h"

using namespace std;
int L16_Parser::Load_Field(Field &p_Field ,string file_Name){

	ifstream field_File(file_Name);
	if (field_File.is_open()){
		int x, y;

		while (field_File >> x >> y){
			stringstream(x) >> x;
			stringstream(y) >> y;
			p_Field.Set_State_LIVE(x+15, y+15);
		}
	}
	else{
		cout << "Could not open file " + file_Name;
		return 1;
	}

	return 0;

}