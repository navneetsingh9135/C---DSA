#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
}; 

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct node* kReverse(struct node* head, int k) {
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    return prev;
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

int main() {
    struct node* head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);
    insertAtTail(&head, 6);
    insertAtTail(&head, 7);
    insertAtTail(&head, 8);
    display(head);

    int k = 3;
    head = kReverse(head, k);
    display(head);

    return 0;
}
