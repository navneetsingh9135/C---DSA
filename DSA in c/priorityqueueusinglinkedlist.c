#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};                  

struct Node* front = NULL;

void enqueue(int item, int priority) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->priority = priority;
    new_node->next = NULL;

    if (front == NULL || front->priority > priority) {
        new_node->next = front;
        front = new_node;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    printf("Enqueued: %d with priority %d\n", item, priority);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        struct Node* temp = front;
        printf("Dequeued: %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        struct Node* temp = front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("(%d, %d) ", temp->data, temp->priority);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(1, 2);
    enqueue(2, 1);
    display();
    dequeue();
    display();
    return 0;
}
