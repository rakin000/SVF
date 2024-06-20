#include <stdio.h>

void updateValue(int *p) {
    *p = *p + 10;
}

void updatePointer(int **pp) {
    *pp = *pp + 1;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    updateValue(ptr);
    printf("Value after update: %d\n", *ptr);  // Should print 11

    updatePointer(&ptr);
    printf("Pointer updated to value: %d\n", *ptr);  // Should print 2

    return 0;
}

