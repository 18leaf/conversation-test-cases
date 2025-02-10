#ifndef DEADLOCK_SIMULATION_H
#define DEADLOCK_SIMULATION_H

#include <mutex>
#include <thread>

class DeadlockSimulation {
public:
	DeadlockSimulation();
	~DeadlockSimulation();

	// Runs two tasks that may deadlock.
	void runDeadlockScenario();

private:
	std::mutex convMutex;
	std::mutex csiMutex;

	// Locks convMutex then csiMutex.
	void taskA();
	// Locks csiMutex then convMutex.
	void taskB();
};

#endif // DEADLOCK_SIMULATION_H
