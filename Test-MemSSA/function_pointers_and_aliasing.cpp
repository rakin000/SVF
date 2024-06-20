#include <stdio.h>

void square(int *x) {
    *x = (*x) * (*x);
}

void triple(int *x) {
    *x = (*x) * 3;
}

void applyFunction(int *value, void (*func)(int *)) {
    func(value);
}

int main() {
    int number = 4;
    applyFunction(&number, square);
    printf("Squared value: %d\n", number);  // Expected: 16

    applyFunction(&number, triple);
    printf("Tripled value: %d\n", number);  // Expected: 48

    return 0;
}

