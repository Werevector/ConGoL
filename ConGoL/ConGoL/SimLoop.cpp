#include "SimLoop.h"

SimLoop::SimLoop(){
	sim_Run = true;
}

SimLoop::SimLoop(Field field){
	sim_Run = true;
}



void SimLoop::RunSim(Field &field){

	if (sim_Run){
	
		Field_Operator::next_Gen(field);
		
	}

}

void SimLoop::StartSim(){
	sim_Run = true;
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
