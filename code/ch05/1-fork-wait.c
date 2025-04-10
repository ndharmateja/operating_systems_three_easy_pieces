#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("[%d] start\n", getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("[%d] from child, rc: %d\n", getpid(), rc);
    }
    else
    {
        int rc_wait = wait(NULL);
        printf("[%d] from parent, rc: %d, rc_wait: %d\n", getpid(), rc, rc_wait);
    }
}