#include "../src/conversation_engine.h"
#include <iostream>

int main() {
	const int numChannels = 20;
	ConversationEngine engine(numChannels);
	std::cout << "Phase 1: Basic Thread Operations" << std::endl;
	engine.runConversation();
	std::cout << "Phase 1: Conversation complete." << std::endl;
	return 0;
}
