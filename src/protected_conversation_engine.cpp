#include "protected_conversation_engine.h"
#include <iostream>
#include <chrono>
#include <thread>

ProtectedConversationEngine::ProtectedConversationEngine(int numChannels)
	: numChannels(numChannels) {}

ProtectedConversationEngine::~ProtectedConversationEngine() {
	for (auto &t : threads)
		if (t.joinable())
			t.join();
}

void ProtectedConversationEngine::channelTask(int channelId) {
	std::string message = "Channel " + std::to_string(channelId) + " says: Hello!";
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	buffer.addMessage(message);
	std::cout << "Channel " << channelId << " posted message." << std::endl;
}

void ProtectedConversationEngine::runConversation() {
	for (int i = 0; i < numChannels; ++i)
		threads.emplace_back(&ProtectedConversationEngine::channelTask, this, i);

	for (auto &t : threads)
		if (t.joinable())
			t.join();

	std::cout << "Final Conversation Buffer:" << std::endl;
	for (const auto &msg : buffer.getMessages())
		std::cout << msg << std::endl;
}
