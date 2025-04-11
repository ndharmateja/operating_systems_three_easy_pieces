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

    int fd = open("q2.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

    int rc = fork();
    if (rc < 0)
        exit(EXIT_FAILURE);

    if (rc == 0)
    {
        for (size_t i = 0; i < 30; i++)
        {
            write(fd, "[child]\n", 9);
        }
    }
    else
    {
        for (size_t i = 0; i < 30; i++)
        {
            write(fd, "[parent]\n", 10);
        }
    }

    return 0;
}