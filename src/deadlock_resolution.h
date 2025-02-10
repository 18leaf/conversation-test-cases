#ifndef DEADLOCK_RESOLUTION_H
#define DEADLOCK_RESOLUTION_H

#include <mutex>
#include <thread>

class DeadlockResolution {
public:
	DeadlockResolution();
	~DeadlockResolution();

	// Runs tasks that acquire locks in a consistent order.
	void runResolutionScenario();

private:
	std::mutex convMutex;
	std::mutex csiMutex;

	void orderedTaskA();
	void orderedTaskB();
};

#endif // DEADLOCK_RESOLUTION_H
