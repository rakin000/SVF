#include <stdio.h>

void updateValue(int *ptr) {
    *ptr = 42;
}

int main() {
    int a = 10;
    updateValue(&a);
    printf("Updated value: %d\n", a);  // Expected: 42
    return 0;
}

