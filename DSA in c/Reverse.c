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
    return newNode;
}

void insertAtHead(struct node** head, int val) {
    struct node* n = createNode(val);
    n->next = *head;
    *head = n;
}

void insertAtTail(struct node** head, int val) {
    struct node* n = createNode(val);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    struct node* head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    display(head);
    head = reverse(head);
    display(head);
    return 0;
}
