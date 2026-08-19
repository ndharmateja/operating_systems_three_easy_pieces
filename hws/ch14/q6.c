#include <stdlib.h>

int main() {
    // Accessing memory after freeing
    int * data = malloc(100 * sizeof(int));
    for (int i = 0; i < 100; i++) {
        data[i] = i;
    }
    free(data);

    // Accessing freed memory
    printf("%d\n", data[0]);
    
    return 0;
}