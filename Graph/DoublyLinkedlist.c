#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
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

// Function to insert a node at the head
void insertAtHead(struct node** head, int val) {
    struct node* n = createNode(val);
    n->next = *head;     
    if (*head != NULL) {
        (*head)->prev = n;
    }
    *head = n;
}   
// Function to insert a node at the tail
void insertAtTail(struct node** head, int val) {
    if (*head == NULL) { 
        insertAtHead(head, val);
        return;
    }

    struct node* n = createNode(val);
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

// Function to display the list
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node* head = NULL;

    // Insert elements at the tail
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    display(head);

    // Insert element at the head
    insertAtHead(&head, 5);
    display(head);

    return 0;
}
