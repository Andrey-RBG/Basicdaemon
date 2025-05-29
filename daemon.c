#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

int main() {
    pid_t pid;
    int i;


    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(-1);
    }


    if (pid > 0) {
        exit(-1);
    }


    if (setsid() < 0) {
        perror("setsid");
        exit(-1);
    }

    if (chdir("/") < 0) {
        perror("chdir");
        exit(0);
    }


    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);


    while (1) {

        sleep(1);
    }

    return 0;
}