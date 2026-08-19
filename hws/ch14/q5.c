#include <stdlib.h>

int main() {
    // Accessing invalid memory - only indices 0 to 99 are valid
    int * data = malloc(100 * sizeof(int));
    data[100] = 0;
    
    return 0;
}