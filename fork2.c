#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  

    if (pid == 0) {
        
        printf("I am the child! My PID = %d\n", getpid());
    } else if (pid > 0) {
        
        printf("I am the parent! My PID = %d, Child PID = %d\n", getpid(), pid);
    } else {
        
        printf("Fork failed!\n");
    }

    return 0;
}
