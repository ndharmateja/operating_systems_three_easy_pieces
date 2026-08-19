#include <stdlib.h>

int main() {
    int * data = malloc(100 * sizeof(int));
    for (int i = 0; i < 100; i++) {
        data[i] = i;
    }
    
    // Freeing using a different invalid pointer
    free(data + 1);
    
    return 0;
}