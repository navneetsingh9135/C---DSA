#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
        if (front > rear) {  // Reset queue if empty
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
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
