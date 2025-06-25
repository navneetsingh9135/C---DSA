#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node *createNode(int val) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the head
void insertAtHead(node **head, int val) {
    node *n = createNode(val);
    n->next = *head;
    *head = n;
}

// Function to insert at the tail
void insertAtTail(node **head, int val) {
    node *n = createNode(val);
    if (*head == NULL) {
        *head = n;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

// Function to display the list
void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the list
int search(node *head, int key) {
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1; // Found
        }
        temp = temp->next;
    }
    return 0; // Not found
}

// Function to delete the head node
void deleteAtHead(node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    node *todelete = *head;
    *head = (*head)->next;
    free(todelete);
}

// Function to delete a node by value
void deletion(node **head, int val) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // If the value to delete is in the head
    if ((*head)->data == val) {
        deleteAtHead(head);
        return;
    }

    node *temp = *head;
    // Traverse until the node before the one to delete
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    // If value is not found
    if (temp->next == NULL) {
        printf("Value %d not found in the list.\n", val);
        return;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    free(todelete);
}

// Main function
int main() {
    node *head = NULL;

    // Insert elements
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    display(head);

    // Insert at the head
    insertAtHead(&head, 4);
    display(head);

    // Search for an element
    printf("Is 4 in the list? %s\n", search(head, 4) ? "Yes" : "No");

    // Delete an element
    deletion(&head, 3);
    display(head);

    // Delete the head
    deleteAtHead(&head);
    display(head);

    // Try deleting a non-existent value
    deletion(&head, 10);

    return 0;
}
