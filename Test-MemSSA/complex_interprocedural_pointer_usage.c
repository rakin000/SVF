#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} DynamicArray;

void initializeArray(DynamicArray *array, int size) {
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = i + 1;
    }
}

void doubleArraySize(DynamicArray *array) {
    int newSize = array->size * 2;
    int *newData = (int *)malloc(newSize * sizeof(int));
    for (int i = 0; i < array->size; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
    array->size = newSize;
}

int main() {
    DynamicArray array;

    initializeArray(&array, 5);

    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);  // Expected: 1 2 3 4 5
    }
    printf("\n");

    doubleArraySize(&array);

    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);  // Expected: 1 2 3 4 5 0 0 0 0 0
    }
    printf("\n");

    free(array.data);
    return 0;
}

