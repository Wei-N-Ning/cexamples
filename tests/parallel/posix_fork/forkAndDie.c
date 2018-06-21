#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_child_process() {
    printf("child: pid (%d); ppid (%d)\n", getpid(), getppid());
}

void continue_parent_process() {
    printf("parent: pid (%d); ppid (%d)\n", getpid(), getppid());
}

int main() {
    pid_t child_pid = fork();
    if (child_pid == (pid_t)-1) {
        perror("fork() failed\n");
        exit(1);
    }
    if (child_pid == 0) {
        execute_child_process();
    } else {
        continue_parent_process();
    }
    waitpid(child_pid, NULL, 0);
    return 0;
}
