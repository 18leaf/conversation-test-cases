#include <iostream>
#include <cstdlib>

int main() {
	std::cout << "Test IPC: Running IPC demo." << std::endl;
	// Assumes that the ipc_demo executable is built in bin/.
	system("./bin/ipc_demo");
	std::cout << "Test IPC: Completed." << std::endl;
	return 0;
}
