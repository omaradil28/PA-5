#pragma once
#include "Queue.h"

class Run {
public:
	Run();
	~Run();

	void runSim();
	void runTest();
	

private:
	int userChoice();
	int randomNum(int);
	void enterLane(int, int, int, Queue&);

	Queue express;
	Queue normal;
};
