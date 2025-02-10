#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipeParentToChild[2];
    int pipeChildToParent[2];

    if (pipe(pipeParentToChild) == -1) {
        std::cerr << "Error creating pipeParentToChild" << std::endl;
        return 1;
    }
    if (pipe(pipeChildToParent) == -1) {
        std::cerr << "Error creating pipeChildToParent" << std::endl;
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Fork failed" << std::endl;
        return 1;
    }

    if (pid == 0) {  // Child process: CSI module simulation.
        close(pipeParentToChild[1]); // Close unused write end.
        close(pipeChildToParent[0]);   // Close unused read end.

        char buffer[256];
        ssize_t bytesRead = read(pipeParentToChild[0], buffer, sizeof(buffer) - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::cout << "CSI Module received: " << buffer << std::endl;
            // Simulate processing delay.
            sleep(1);
            const char* response = "RETURN|Processed: [Simulated Embedding]";
            write(pipeChildToParent[1], response, strlen(response));
        }
        close(pipeParentToChild[0]);
        close(pipeChildToParent[1]);
        return 0;
    } else {  // Parent process: Conversation Engine.
        close(pipeParentToChild[0]); // Close unused read end.
        close(pipeChildToParent[1]);   // Close unused write end.

        const char* command = "SEND|Hello CSI Module";
        write(pipeParentToChild[1], command, strlen(command));
        std::cout << "Conversation Engine sent: " << command << std::endl;

        char buffer[256];
        ssize_t bytesRead = read(pipeChildToParent[0], buffer, sizeof(buffer) - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::cout << "Conversation Engine received: " << buffer << std::endl;
        }
        wait(nullptr);

        close(pipeParentToChild[1]);
        close(pipeChildToParent[0]);
    }

    return 0;
}
