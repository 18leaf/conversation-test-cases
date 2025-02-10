#include "../src/deadlock_resolution.h"
#include <iostream>

int test4() {
	DeadlockResolution res;
	std::cout << "Test Phase 4: Deadlock Resolution" << std::endl;
	res.runResolutionScenario();
	std::cout << "Test Phase 4: Completed without deadlock." << std::endl;
	return 0;
}
