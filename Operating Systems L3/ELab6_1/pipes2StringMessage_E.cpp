#include <sys/wait.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

std::string pipeRead(int pipe)
{
    std::string message;
    char buffer[128];
    ssize_t bytesRead;

    // Read from the pipe
    bytesRead = read(pipe, buffer, sizeof(buffer) - 1);
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the string
        message = std::string(buffer);
    }

    return message;
}

void pipeWrite(int pipe, std::string message)
{
    // Write the message to the pipe
    write(pipe, message.c_str(), message.size());
}

std::vector<std::array<int, 2>> createPipes(int count)
{
    std::vector<std::array<int, 2>> pipes;

    for (int i = 0; i < count; ++i)
    {
        std::array<int, 2> newPipe;

        // Create a pipe and fill the array
        if (pipe(newPipe.data()) == -1) {
            perror("Error creating pipe.");
            exit(EXIT_FAILURE);
        }

        pipes.push_back(newPipe);
    }

    return pipes;
}

int main(int argc, char* argv[])
{
    auto pipes = createPipes(1);

    if (fork() == 0)
    {
        // Child process
        close(pipes[0][0]); // Close unused read end
        std::string message = "message sent through the pipe";
        pipeWrite(pipes[0][1], message);
        close(pipes[0][1]); // Close the write end after sending
    }
    else
    {
        // Parent process
        close(pipes[0][1]); // Close unused write end
        std::string message = pipeRead(pipes[0][0]);
        close(pipes[0][0]); // Close the read end after receiving
        std::cout << message << "\n";
    }

    return 0;
}
