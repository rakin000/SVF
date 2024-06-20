#include <stdio.h>
#include <stdlib.h>

void fillArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i * i;
    }
}

int main() {
    int size = 10;
    int *dynamicArray = (int *)malloc(size * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    fillArray(dynamicArray, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);  // Expected: 0 1 4 9 16 25 36 49 64 81
    }
    printf("\n");

    free(dynamicArray);
    return 0;
}

