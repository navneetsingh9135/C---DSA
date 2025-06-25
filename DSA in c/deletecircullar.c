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

void insertAtHead(struct node** head, int val) {
    struct node* n = createNode(val);
    if (*head == NULL) {
        n->next = n;
        *head = n;
        return;
    }
    struct node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = *head;
    *head = n;
}

void insertAtTail(struct node** head, int val) {
    if (*head == NULL) {
        insertAtHead(head, val);
        return;
    }
    struct node* n = createNode(val);
    struct node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = *head;
}

void deleteAtHead(struct node** head) {
    struct node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next; 
    }
    struct node* todelete = *head;
    temp->next = (*head)->next;
    *head = (*head)->next;
    free(todelete);
}

void deletion(struct node** head, int pos) {
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }
    struct node* temp = *head;
    int count = 1;
    while (count != pos - 1) {
        temp = temp->next;
        count++;
    }
    struct node* todelete = temp->next;
    temp->next = temp->next->next;
    free(todelete);
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
    deletion(&head, 5);
    display(head);
    return 0;
}
