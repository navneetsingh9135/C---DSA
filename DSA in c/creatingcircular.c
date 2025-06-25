#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = *head_ref; // Link the new node to the head

    if (*head_ref != NULL) {
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = new_node; // Update the last node to point to new node
    } else {
        new_node->next = new_node; // For the first node
    }

    *head_ref = new_node;
}

void display(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("Circular Linked List: ");
    display(head);

    return 0;
}
