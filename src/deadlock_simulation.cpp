#include "deadlock_simulation.h"
#include <iostream>
#include <chrono>
#include <thread>

DeadlockSimulation::DeadlockSimulation() = default;
DeadlockSimulation::~DeadlockSimulation() = default;

void DeadlockSimulation::taskA() {
	std::cout << "Task A acquiring convMutex..." << std::endl;
	convMutex.lock();
	std::cout << "Task A acquired convMutex. Now acquiring csiMutex..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	csiMutex.lock();
	std::cout << "Task A acquired csiMutex." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	csiMutex.unlock();
	convMutex.unlock();
	std::cout << "Task A released both locks." << std::endl;
}

void DeadlockSimulation::taskB() {
	std::cout << "Task B acquiring csiMutex..." << std::endl;
	csiMutex.lock();
	std::cout << "Task B acquired csiMutex. Now acquiring convMutex..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	convMutex.lock();
	std::cout << "Task B acquired convMutex." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	convMutex.unlock();
	csiMutex.unlock();
	std::cout << "Task B released both locks." << std::endl;
}

void DeadlockSimulation::runDeadlockScenario() {
	std::thread t1(&DeadlockSimulation::taskA, this);
	std::thread t2(&DeadlockSimulation::taskB, this);

	// These joins may hang if deadlock occurs
	std::cout << "t1 joining" << std::endl;
	t1.join();
	std::cout << "t1 finished joining" << std::endl;
	std::cout << "t2 joining" << std::endl;
	t2.join();
	std::cout << "t2 finished joining" << std::endl;
}
