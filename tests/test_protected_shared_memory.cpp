#include "../src/protected_conversation_engine.h"
#include <iostream>

int main() {
	const int numChannels = 20;
	ProtectedConversationEngine engine(numChannels);
	std::cout << "Test Phase 2: Resource Protection" << std::endl;
	engine.runConversation();
	std::cout << "Test Phase 2: Passed." << std::endl;
	return 0;
}
