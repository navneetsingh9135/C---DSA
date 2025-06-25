#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the linked list
void insertAtHead(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the tail of the linked list
void insertAtTail(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;

    // Insert nodes at the tail
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);
    display(head);

    // Insert nodes at the head
    insertAtHead(&head, 0);
    display(head);

    insertAtHead(&head, -1);
    display(head);

    // Insert another node at the tail
    insertAtTail(&head, 6);
    display(head);

    return 0;
}
