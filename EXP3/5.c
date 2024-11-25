#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to delete the linked list
void deleteList(struct Node* head) {
    // Base case: if the list is empty
    if (head == NULL) {
        return;
    }

    // Recursive case: move to the next node
    deleteList(head->next);

    // Delete the current node
    printf("Deleting node with data: %d\n", head->data);
    free(head);
}

// Function to print the list (for testing purposes)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Print the original list
    printf("Original Linked List:\n");
    printList(head);

    // Delete the linked list
    deleteList(head);

    // After deleting, head is NULL, so print it again
    printf("\nAfter Deleting the Linked List:\n");
    printList(head);  // This will print nothing as the list is deleted

    return 0;
}
