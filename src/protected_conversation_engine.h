#ifndef PROTECTED_CONVERSATION_ENGINE_H
#define PROTECTED_CONVERSATION_ENGINE_H

#include "conversation_buffer.h"
#include <vector>
#include <thread>

class ProtectedConversationEngine {
public:
	explicit ProtectedConversationEngine(int numChannels);
	~ProtectedConversationEngine();

	// Runs threads that post messages to a shared buffer.
	void runConversation();

private:
	int numChannels;
	ConversationBuffer buffer;
	std::vector<std::thread> threads;

	void channelTask(int channelId);
};

#endif // PROTECTED_CONVERSATION_ENGINE_H
