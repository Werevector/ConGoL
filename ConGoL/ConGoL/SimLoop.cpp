#include "SimLoop.h"

SimLoop::SimLoop(){

}

SimLoop::SimLoop(Field field){
	//s_Field = field
}



void SimLoop::StartSim(){

	while (sim_Run){
	
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
