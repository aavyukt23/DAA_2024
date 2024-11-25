#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to split the list into two halves
void splitList(struct Node* head, struct Node** firstHalf, struct Node** secondHalf) {
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;

    // Move fast by two and slow by one step to find the middle
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Split the list into two halves
    *firstHalf = head;
    *secondHalf = slow;
    prev->next = NULL;  // Disconnect the two halves
}

// Function to merge two sorted lists
struct Node* merge(struct Node* first, struct Node* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    // If the first element is smaller, recursively merge
    if (first->data <= second->data) {
        first->next = merge(first->next, second);
        return first;
    } else {
        second->next = merge(first, second->next);
        return second;
    }
}

// Merge Sort function for linked list
struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;  // Base case: a list with 0 or 1 element is already sorted
    }

    struct Node* firstHalf = NULL;
    struct Node* secondHalf = NULL;

    // Split the list into two halves
    splitList(head, &firstHalf, &secondHalf);

    // Recursively sort the two halves
    firstHalf = mergeSort(firstHalf);
    secondHalf = mergeSort(secondHalf);

    // Merge the sorted halves
    return merge(firstHalf, secondHalf);
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to push a new node to the front of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Main function to test merge sort on linked list
int main() {
    struct Node* head = NULL;

    // Creating a linked list
    push(&head, 12);
    push(&head, 11);
    push(&head, 13);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);

    printf("Original Linked List: \n");
    printList(head);

    // Sorting the linked list using merge sort
    head = mergeSort(head);

    printf("Sorted Linked List: \n");
    printList(head);

    return 0;
}
