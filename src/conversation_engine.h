#ifndef CONVERSATION_ENGINE_H
#define CONVERSATION_ENGINE_H

#include <vector>
#include <thread>
#include <string>

class ConversationEngine {
public:
	explicit ConversationEngine(int numChannels);
	~ConversationEngine();

	// Spawns threads simulating conversation channels.
	void runConversation();

private:
	int numChannels;
	std::vector<std::thread> threads;

	// Each channel simulates sending a message.
	void channelTask(int channelId);
};

#endif // CONVERSATION_ENGINE_H
