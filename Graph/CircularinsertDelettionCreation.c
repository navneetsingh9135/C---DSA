#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
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
    if (*head == NULL) {
        n->next = n;
        *head = n;
        return;
    }
    node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = *head;
    *head = n;
}

// Function to insert at the tail
void insertAtTail(node **head, int val) {
    if (*head == NULL) {
        insertAtHead(head, val);
        return;
    }
    node *n = createNode(val);
    node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = *head;
}

// Function to delete the head node
void deleteAtHead(node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    node *todelete = *head;
    temp->next = (*head)->next;
    *head = (*head)->next;
    free(todelete);
}

// Function to delete a node by position
void deletion(node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }
    node *temp = *head;
    int count = 1;
    while (count != pos - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }
    if (temp->next == *head) {
        printf("Position %d is out of bounds.\n", pos);
        return;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    free(todelete);
}

// Function to display the list
void display(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    node *head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    display(head);
    insertAtHead(&head, 5);
    display(head);
    deletion(&head, 5);
    display(head);
    return 0;
}
