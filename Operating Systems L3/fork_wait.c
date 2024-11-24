#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;
    int num1, num2, sum;
    char name[50];

    // Create the first child process
    pid1 = fork();
    if (pid1 == 0) {  // Child 1 process
        printf("Child 1: Enter two numbers to add: ");
        fflush(stdout);  // Ensure the message is displayed immediately
        scanf("%d %d", &num1, &num2);
        sum = num1 + num2;
        printf("Child 1: The sum is: %d\n", sum);
        exit(EXIT_SUCCESS);
    }

    // Wait for child 1 to complete before proceeding to child 2
    waitpid(pid1, NULL, 0); 

    // Create the second child process
    pid2 = fork();
    if (pid2 == 0) {  // Child 2 process
        printf("Child 2: Enter your name: ");
        fflush(stdout);  // Ensure the message is displayed immediately
        scanf("%s", name);
        printf("Child 2: Hello, %s!\n", name);
        exit(EXIT_SUCCESS);
    }

    // Wait for child 2 to complete
    waitpid(pid2, NULL, 0);

    printf("All child processes completed.\n");

    return 0;
}

