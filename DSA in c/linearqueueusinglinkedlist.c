#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int item) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = NULL;
    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    printf("Enqueued: %d\n", item);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        struct Node* temp = front;
        printf("Dequeued: %d\n", temp->data);
        front = front->next;
        free(temp);
        if (front == NULL) {
            rear = NULL;
        }
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        struct Node* temp = front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    display();
    dequeue();
    display();
    return 0;
}
