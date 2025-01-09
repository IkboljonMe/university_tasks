#include <sys/wait.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

const int rows = 3;
const int columns = 7;

bool pipeRead(int pipe, int& value)
{
    int readed = 0;
    readed = read(pipe, &value, sizeof(value));
    if (readed == -1)
    {
        perror("Error reading pipe.");
        exit(EXIT_FAILURE);
    }
    else if (readed == 0)
        return false;
    return true;
}

void pipeWrite(int pipe, int value)
{
    if (write(pipe, &value, sizeof(value)) == -1)
    {
        perror("Error writing pipe.");
        exit(EXIT_FAILURE);
    }
}

std::vector<std::array<int, 2>> createPipes(int count)
{
    std::vector<std::array<int, 2>> pipes;
    for (int i = 0; i < count; ++i)
    {
        std::array<int, 2> newPipe;
        int* data = newPipe.data(); // data is the pointer to a 2-element table of int
        if (pipe(newPipe.data()) == -1)
        {
            perror("Error creating pipe.");
            exit(EXIT_FAILURE);
        }
        pipes.push_back(newPipe);
    }
    return pipes;
}

void computeAverageForRow(std::array<int, columns> values, int p)
{
    int sum = 0;
    for (auto v : values)
        sum += v;

    pipeWrite(p, sum);
    pipeWrite(p, values.size());
}

int main(int argc, char* argv[])
{
    std::array<std::array<int, columns>, rows> values = { { {3,4,6,8,9,7,8}, {6,2,6,1,7,9,0}, {0,9,0,2,4,1,2} } };

    int read_pipes[rows];

    for (int i = 0; i < rows; ++i)
    {
        int p[2];
        pipe(p);

        pid_t pid = fork();
        if (pid == -1)
        {
            perror("Error creating process.");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // CHILD PROCESS
            close(p[0]); // CLOSE READ END
            computeAverageForRow(values[i], p[1]);
            close(p[1]); // CLOSE WRITE END
            exit(0);     // TERMINATE CHILD PROCESS
        }
        else
        {
            // PARENT PROCESS
            close(p[1]);      // CLOSE WRITE END
            read_pipes[i] = p[0]; // SAVE READ END IN TABLE
        }
    }

    // WAIT FOR ALL CHILD PROCESSES TO FINISH
    for (int i = 0; i < rows; ++i)
    {
        wait(NULL);
    }

    // PARENT PROCESS: COLLECT RESULTS FROM CHILDREN
    int sum = 0;
    int count = 0;
    for (int i = 0; i < rows; ++i)
    {
        int value;
        pipeRead(read_pipes[i], value);
        sum += value;
        pipeRead(read_pipes[i], value);
        count += value;
        close(read_pipes[i]);
    }

    float average = 0.0f;
    if (count > 0)
        average = (float)sum / count;
    std::cout << "Average: " << average << "\n";
    return 0;
}
