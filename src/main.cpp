#include "conversation_engine.h"
#include <iostream>

int main() {
	const int numChannels = 20;
	ConversationEngine engine(numChannels);
	std::cout << "Starting CSI system conversation simulation." << std::endl;
	engine.runConversation();
	std::cout << "Conversation simulation complete." << std::endl;
	return 0;
}
