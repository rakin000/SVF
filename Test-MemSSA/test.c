#include <stdio.h>

// Function to swap the values of two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to calculate the sum and difference of two numbers using pointers
void calculateSumAndDifference(int num1, int num2, int *sum, int *difference) {
    *sum = num1 + num2;
    *difference = num1 - num2;
}

int main() {
    int num1 = 5, num2 = 10;
    int sum, difference;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Passing the addresses of num1 and num2 to the swap function
    swap(&num1, &num2);

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Passing values and addresses to calculateSumAndDifference function
    calculateSumAndDifference(num1, num2, &sum, &difference);

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);

    return 0;
}

