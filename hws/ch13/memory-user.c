#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if(argc != 2) {
        printf("Usage: ./program <megabytes>\n");
        return 1;
    }

    double mb = atof(argv[1]);
    long long bytes = (long long) (mb * 1024) * 1024;
    int num_elements = bytes / sizeof(int);

    printf("bytes: %llu\n", bytes);
    printf("Number of elements: %d\n", num_elements);
    printf("Process ID: %u\n", getpid());

    int *array = (int *) malloc(num_elements * sizeof(int));
    while (1) {
        for(int i = 0; i < num_elements; i++)
            array[i] = i;
    }

    return 0;
}
