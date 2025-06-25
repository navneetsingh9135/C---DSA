#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int val) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    return n;
}

// Insert at head
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

// Insert at Tail
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

// Display the circular linked list
void display(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
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
    int choice, val;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Display the List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at head: ");
                scanf("%d", &val);
                insertAtHead(&head, val);
                break;
            case 2:
                printf("Enter the value to insert at tail: ");
                scanf("%d", &val);
                insertAtTail(&head, val);
                break;
            case 3:
                printf("The circular linked list is: ");
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}
