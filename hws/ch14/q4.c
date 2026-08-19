#include <stdlib.h>

int main() {
    // Not freeing memory obtained from malloc
    int * ptr = malloc(sizeof(int));
    printf("%d\n", *ptr);
    *ptr = 100;
    printf("%d\n", *ptr);

    return 0;
}