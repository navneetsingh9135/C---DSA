#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {  // Reset queue if empty
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        int i = front;
        printf("Queue: ");
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
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
