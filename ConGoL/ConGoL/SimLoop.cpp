#include "SimLoop.h"

SimLoop::SimLoop(){
	sim_Run = true;
}

SimLoop::SimLoop(Field field){
	s_Field = field;
	sim_Run = true;
}



void SimLoop::StartSim(Field &field){

	if (sim_Run){
	
		Field_Operator::next_Gen(s_Field);
		
	}

}

void SimLoop::StopSim(){
	sim_Run = false;
}

void SimLoop::runOnce(Field &field){
	Field_Operator::next_Gen(field);
}

Field SimLoop::get_simField(){
	return s_Field;
}
