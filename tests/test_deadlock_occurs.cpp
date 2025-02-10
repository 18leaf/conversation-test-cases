#include "../src/deadlock_simulation.h"
#include <iostream>

int test3() {
	DeadlockSimulation sim;
	std::cout << "Test Phase 3: Deadlock Creation" << std::endl;
	// Note: This test may hang if a deadlock occurs.
	sim.runDeadlockScenario();
	std::cout << "If both tasks completed, deadlock did not occur. Otherwise, the process hangs." << std::endl;
	return 0;
}
