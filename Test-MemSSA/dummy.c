#include <stdio.h>

int main() {
    // Declare a variable and initialize it
    int number = 42;

    // Declare a pointer and assign the address of the variable to it
    int *pointer_to_number = &number;

    // Print the value and address of the variable using the pointer
    printf("Value of number: %d\n", *pointer_to_number);
    printf("Address of number: %p\n", (void*)pointer_to_number);

    // Modify the value of the variable through the pointer
    *pointer_to_number = 99;

    // Print the updated value of the variable
    printf("Updated value of number: %d\n", number);

    return 0;
}
