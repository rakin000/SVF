#include <stdio.h>

void increment(int *x) {
    (*x)++;
}

void doubleValue(int *x) {
    *x *= 2;
}

int main() {
    int value = 5;
    int *ptr1 = &value;
    int *ptr2 = &value;

    increment(ptr1);
    doubleValue(ptr2);

    printf("Final value: %d\n", value);  // Expected: 12
    return 0;
}

