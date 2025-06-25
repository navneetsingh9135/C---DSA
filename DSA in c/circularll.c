//Insertion in Circular Linkedlist//
#include <stdio.h>
#include <stdlib.h>                                                                                                                                                               

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode// Return the pointer to the new node;
}
//Insert at head
void insertAtHead(struct node** head, int val) {
    struct node* newNode = createNode(val);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}
//Insert at Tail//
void insertAtTail(struct node** head, int val) {
    if (*head == NULL) {
        insertAtHead(head, val);
        return;
    }
    struct node* newNode = createNode(val);
    struct node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}


void display(struct node* head) {
    if (head == NULL) {
        return;
    }
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);                                                                                                                                                             
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    display(head);
    insertAtHead(&head, 5);
    display(head);
    return 0;
}
