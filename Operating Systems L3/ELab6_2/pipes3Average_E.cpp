#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <array>

void pipeRead(int pipe, int& value) {
    // Read from the pipe
    if (read(pipe, &value, sizeof(value)) <= 0) {
        perror("Error reading from pipe");
        exit(EXIT_FAILURE);
    }
}

void pipeWrite(int pipe, int value) {
    // Write to the pipe
    if (write(pipe, &value, sizeof(value)) <= 0) {
        perror("Error writing to pipe");
        exit(EXIT_FAILURE);
    }
}

std::vector<std::array<int, 2>> createPipes(int count) {
    // Create the specified number of pipes
    std::vector<std::array<int, 2>> pipes;
    for (int i = 0; i < count; ++i) {
        std::array<int, 2> newPipe;
        if (pipe(newPipe.data()) == -1) {
            perror("Error creating pipe");
            exit(EXIT_FAILURE);
        }
        pipes.push_back(newPipe);
    }
    return pipes;
}

int main() {
    auto pipes = createPipes(2); // Create two pipes

    if (fork() == 0) { // First Child Process
        close(pipes[0][0]); // Close read end of the first pipe
        close(pipes[1][0]); // Close read end of the second pipe
        close(pipes[1][1]); // Close write end of the second pipe

        int value;
        std::cout << "Child 1: Enter integers (end with -1):\n";
        while (true) {
            std::cin >> value; // Read input from user
            pipeWrite(pipes[0][1], value); // Write value to the first pipe
            if (value == -1) break; // Exit signal
        }

        close(pipes[0][1]); // Close write end of the first pipe
        exit(0); // Exit Child 1
    }

    if (fork() == 0) { // Second Child Process
        close(pipes[0][1]); // Close write end of the first pipe
        close(pipes[1][0]); // Close read end of the second pipe

        int value, sum = 0, count = 0;
        std::cout << "Child 2: Receiving numbers...\n";
        while (true) {
            pipeRead(pipes[0][0], value); // Read from the first pipe
            if (value == -1) break; // Exit signal
            sum += value; // Calculate sum
            count++;
            pipeWrite(pipes[1][1], value); // Write to the second pipe
        }

        close(pipes[0][0]); // Close read end of the first pipe
        close(pipes[1][1]); // Close write end of the second pipe

        if (count > 0) {
            std::cout << "Child 2 - Average: " << static_cast<double>(sum) / count << "\n";
        }
        exit(0); // Exit Child 2
    }

    // Parent Process
    close(pipes[0][0]); // Close read end of the first pipe
    close(pipes[0][1]); // Close write end of the first pipe
    close(pipes[1][1]); // Close write end of the second pipe

    int value;
    std::cout << "Parent: Receiving numbers...\n";
    while (true) {
        pipeRead(pipes[1][0], value); // Read from the second pipe
        if (value == -1) break; // Exit signal
        std::cout << "Parent: " << value << "\n"; // Print received value
    }

    close(pipes[1][0]); // Close read end of the second pipe

    // Wait for children to complete
    wait(NULL); // Wait for Child 1
    wait(NULL); // Wait for Child 2

    return 0;
}
