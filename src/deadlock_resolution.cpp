#include "deadlock_resolution.h"
#include <iostream>
#include <chrono>
#include <thread>

DeadlockResolution::DeadlockResolution() = default;
DeadlockResolution::~DeadlockResolution() = default;

void DeadlockResolution::orderedTaskA() {
	// Enforce global ordering: always acquire convMutex then csiMutex.
	std::lock(convMutex, csiMutex);
	std::lock_guard<std::mutex> lock1(convMutex, std::adopt_lock);
	std::lock_guard<std::mutex> lock2(csiMutex, std::adopt_lock);

	std::cout << "Ordered Task A acquired locks." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	std::cout << "Ordered Task A completed work." << std::endl;
}

void DeadlockResolution::orderedTaskB() {
	// Use the same ordering.
	std::lock(convMutex, csiMutex);
	std::lock_guard<std::mutex> lock1(convMutex, std::adopt_lock);
	std::lock_guard<std::mutex> lock2(csiMutex, std::adopt_lock);

	std::cout << "Ordered Task B acquired locks." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	std::cout << "Ordered Task B completed work." << std::endl;
}

void DeadlockResolution::runResolutionScenario() {
	std::thread t1(&DeadlockResolution::orderedTaskA, this);
	std::thread t2(&DeadlockResolution::orderedTaskB, this);

	t1.join();
	t2.join();
}
