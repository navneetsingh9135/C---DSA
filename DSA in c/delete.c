#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the head
void insertAtHead(struct node **head, int val) {
    struct node *newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert at the tail
void insertAtTail(struct node **head, int val) {
    struct node *newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the list
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the list
int search(struct node *head, int key) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1; // Found
        }
        temp = temp->next;
    }
    return 0; // Not found
}

// Function to delete the head node
void deleteAtHead(struct node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node *toDelete = *head;
    *head = (*head)->next;
    free(toDelete);
}

// Function to delete a node by value
void deletion(struct node **head, int val) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // If the value to delete is in the head
    if ((*head)->data == val) {
        deleteAtHead(head);
        return;
    }

    struct node *temp = *head;
    // Traverse until the node before the one to delete
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    // If value is not found
    if (temp->next == NULL) {
        printf("Value %d not found in the list.\n", val);
        return;
    }

    struct node *toDelete = temp->next;
    temp->next = temp->next->next;

    free(toDelete);
}

// Main function
int main() {
    struct node *head = NULL;

    // Insert elements at the tail
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
