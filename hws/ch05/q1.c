/**
 * Write a program that calls fork(). Before calling fork(), have the
 * main process access a variable (e.g., x) and set its value to something (e.g., 100).
 * What value is the variable in the child process?
 * What happens to the variable when both the child and parent change
the value of x? */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int x = 100;
    printf("[%d] x: %d\n", getpid(), x);

    int rc = fork();
    if (rc < 0)
        exit(EXIT_FAILURE);

    if (rc == 0)
    {
        // Child process
        printf("[%d] x: %d\n", getpid(), x);
        printf("[%d] Changing x to 200\n", getpid());
        x = 200;
        printf("[%d] x: %d\n", getpid(), x);
    }
    else
    {
        // Parent process

        // Wait for child
        wait(NULL);
        printf("[%d] x: %d\n", getpid(), x);
        printf("[%d] Changing x to 300\n", getpid());
        x = 300;
        printf("[%d] x: %d\n", getpid(), x);
    }

    return 0;
}