#include <stdlib.h>
#include <stdio.h>

int main() {
    // Dereferencing a null ptr
    int * ptr = NULL;
    printf("%d\n", *ptr);
    return 0;
}