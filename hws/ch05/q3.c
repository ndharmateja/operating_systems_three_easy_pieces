/**
 * Write a program that calls fork(). Before calling fork(), have the
 * main process access a variable (e.g., x) and set its value to something (e.g., 100).
 * What value is the variable in the child process?
 * What happens to the variable when both the child and parent change
the value of x? */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{

    int rc = fork();
    if (rc < 0)
        exit(EXIT_FAILURE);

    if (rc == 0)
    {
        printf("hello\n");
    }
    else
    {
        wait(NULL);
        printf("good bye\n");
    }

    return 0;
}