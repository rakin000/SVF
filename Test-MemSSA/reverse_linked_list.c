#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list without modifying the original list
Node* reverseList(Node* head) {
    Node* reversedHead = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* newNode = createNode(current->data);
        newNode->next = reversedHead;
        reversedHead = newNode;
        current = current->next;
    }
    return reversedHead;
}

int main() {
    Node* originalList = NULL;

    // Append some nodes to the original list
    appendNode(&originalList, 1);
    appendNode(&originalList, 2);
    appendNode(&originalList, 3);
    appendNode(&originalList, 4);
    appendNode(&originalList, 5);

    printf("Original List: ");
    printList(originalList);

    // Reverse the list without modifying the original list
    Node* reversedList = reverseList(originalList);

    printf("Reversed List: ");
    printList(reversedList);

    // Free the reversed list to avoid memory leaks
    Node* temp;
    while (reversedList != NULL) {
        temp = reversedList;
        reversedList = reversedList->next;
        free(temp);
    }

    // Free the original list to avoid memory leaks
    while (originalList != NULL) {
        temp = originalList;
        originalList = originalList->next;
        free(temp);
    }

    return 0;
}
