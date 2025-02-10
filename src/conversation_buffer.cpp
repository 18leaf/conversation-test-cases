#include "conversation_buffer.h"

void ConversationBuffer::addMessage(const std::string &msg) {
	std::lock_guard<std::mutex> lock(mtx);
	messages.push_back(msg);
}

std::vector<std::string> ConversationBuffer::getMessages() {
	std::lock_guard<std::mutex> lock(mtx);
	return messages;
}
