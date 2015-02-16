#pragma once
#pragma once
#include "GameTimer.h"
#include "Field.h"
#include "Field_Operator.h"
#include "Field_Renderer.h"

//class for looping through a simulation on an integer field
class SimLoop{


public:

	

	//Default Field Loop
	SimLoop();
	
	//Custom Field Loop
	SimLoop(Field field);

	void StartSim(Field &field);
	void StopSim();

	void runOnce(Field &field);

	Field get_simField();



private:

	Field s_Field;
	bool sim_Run;
	GameTimer s_Timer;


};