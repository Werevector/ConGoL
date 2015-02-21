#include "L16_FParser.h"

using namespace std;
int L16_Parser::Load_Field(Field &p_Field ,string file_Name){

	ifstream field_File(file_Name);
	if (field_File.is_open()){
		int x, y;
		string line;
		while (getline(field_File, line)){
			if (line[0] != '#'){
				istringstream(line) >> x >> y;
				
				/*x += (p_Field.get_FieldSize_X() / 2);
				y += (p_Field.get_FieldSize_Y() / 2);*/

				p_Field.Set_State_LIVE(x, y);
				p_Field.add_Cell_wPadd(x, y);
			}
		}
	}
	else{
		cout << "Could not open file " + file_Name;
		return 1;
	}

	return 0;

}