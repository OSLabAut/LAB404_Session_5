#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process (PID=%d) is running...\n", getpid());
        sleep(2);
        printf("Child process done.\n");
    } else {
        printf("Parent waiting for child...\n");
        wait(NULL); 
        printf("Parent: child finished.\n");
    }

    return 0;
}
