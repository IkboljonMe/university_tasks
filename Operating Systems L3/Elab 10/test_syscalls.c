#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

#define SYS_MAXCHILDREN 442 // Replace with actual syscall number
#define SYS_WHOMAXCHILDREN 443 // Replace with actual syscall number

int main() {
    int max_children = 5;
    int result;

    result = syscall(SYS_MAXCHILDREN, max_children);
    if (result == -1) {
        perror("MAXCHILDREN syscall failed");
        return 1;
    }
    printf("Set maximum children to %d.\n", max_children);

    for (int i = 0; i < max_children + 2; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child process %d created.\n", getpid());
            sleep(10);
            return 0;
        } else if (pid < 0) {
            perror("Fork failed");
        }
    }

    pid_t max_pid;
    result = syscall(SYS_WHOMAXCHILDREN, &max_pid);
    if (result == -1) {
        perror("WHOMAXCHILDREN syscall failed");
        return 1;
    }
    printf("Process with max children limit: PID %d\n", max_pid);

    return 0;
}
