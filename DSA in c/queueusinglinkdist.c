#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    int* arr;
    int front;
    int back;
    int n; // size of the queue
} Queue;

// Function to create a queue
Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->n = size;
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = -1;
    q->back = -1;
    return q;
}

// Function to push an element into the queue
void push(Queue* q, int x) {
    if (q->back == q->n - 1) {
        printf("Queue overflow\n");
        return;
    }
    q->back++;
    q->arr[q->back] = x;
    if (q->front == -1) {
        q->front++;
    }
}

// Function to pop an element from the queue
void pop(Queue* q) {
    if (q->front == -1 || q->front > q->back) {
        printf("No element in queue\n");
        return;
    }
    q->front++;
}

// Function to get the front element
int peek(Queue* q) {
    if (q->front == -1 || q->front > q->back) {
        printf("Queue underflow\n");
        return -1;
    }
    return q->arr[q->front];
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->back);
}

// Function to free the allocated memory
void freeQueue(Queue* q) {
    free(q->arr);
    free(q);
}

int main() {
    Queue* q = createQueue(5); // Provide a size to the queue

    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);

    printf("%d\n", peek(q));  // Outputs the front element
    pop(q);
    printf("%d\n", peek(q));  // Outputs the next front element
    pop(q);
    printf("%d\n", peek(q));  // Outputs the next front element
    pop(q);
    printf("%d\n", isEmpty(q));  // Check if queue is empty

    freeQueue(q);  // Free allocated memory
    return 0;
}
    