#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create a new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert at the head
void insertAtHead(struct node** head, int val) {
    struct node* newNode = createNode(val);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert at the tail
void insertAtTail(struct node** head, int val) {
    if (*head == NULL) {
        insertAtHead(head, val);
        return;
    }

    struct node* newNode = createNode(val);
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the head node
void deleteAtHead(struct node** head) {
    if (*head == NULL) return;

    struct node* toDelete = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(toDelete);
}

int main() {
    struct node* head = NULL;

    // Insert elements at the tail
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);

    // Display the list
    printf("List after inserting at tail: ");
    display(head);

    // Insert element at the head
    insertAtHead(&head, 0);
    printf("List after inserting at head: ");
    display(head);

    // Delete the head node
    deleteAtHead(&head);
    printf("List after deleting the head: ");
    display(head);

    return 0;
}
