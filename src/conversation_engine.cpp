#include "conversation_engine.h"
#include <iostream>
#include <chrono>
#include <thread>

ConversationEngine::ConversationEngine(const int numChannels)
	: numChannels(numChannels) {}

ConversationEngine::~ConversationEngine() {
	for (auto &t : threads) {
		if (t.joinable())
			t.join();
	}
}

void ConversationEngine::channelTask(const int channelId) {
	std::cout << "Channel " << channelId << " starting conversation." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "Channel " << channelId
			  << " sends: 'Hello from channel " << channelId << "'." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout << "Channel " << channelId << " finished conversation." << std::endl;
}

void ConversationEngine::runConversation() {
	for (int i = 0; i < numChannels; ++i)
		threads.emplace_back(&ConversationEngine::channelTask, this, i);

	for (auto &t : threads)
		if (t.joinable())
			t.join();
}
