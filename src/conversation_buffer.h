#ifndef CONVERSATION_BUFFER_H
#define CONVERSATION_BUFFER_H

#include <vector>
#include <string>
#include <mutex>

class ConversationBuffer {
public:
	// Add a message to the buffer in a thread-safe manner.
	void addMessage(const std::string &msg);
	// Retrieve a copy of the messages.
	std::vector<std::string> getMessages();

private:
	std::vector<std::string> messages;
	std::mutex mtx;
};

#endif // CONVERSATION_BUFFER_H
