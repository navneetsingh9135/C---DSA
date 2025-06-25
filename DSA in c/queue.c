#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* arr;
    int front;
    int back;
    int n; // size of the queue
} Queue;

void initQueue(Queue* q, int size) {
    q->n = size;
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = -1;
    q->back = -1;
}

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

void pop(Queue* q) {
    if (q->front == -1 || q->front > q->back) {
        printf("No element in queue\n");
        return;
    }
    q->front++;
}

int peek(Queue* q) {
    if (q->front == -1 || q->front > q->back) {
        printf("Queue underflow\n");
        return -1;
    }
    return q->arr[q->front];
}

int empty(Queue* q) {
    if (q->front == -1 || q->front > q->back) {
        return 1; // True
    }
    return 0; // False
}

void freeQueue(Queue* q) {
    free(q->arr); // Free the dynamically allocated memory
}

int main() {
    Queue q;
    initQueue(&q, 5); // Provide a size to the queue

    push(&q, 1);
    push(&q, 2);
    push(&q, 3);
    push(&q, 4);
    
    printf("%d\n", peek(&q));  // Outputs the front element
    pop(&q);
    printf("%d\n", peek(&q));  // Outputs the next front element
    pop(&q);
    printf("%d\n", peek(&q));  // Outputs the next front element
    pop(&q);
    printf("%d\n", empty(&q));  // Check if queue is empty (1 for true, 0 for false)

    freeQueue(&q); // Free the allocated memory for the queue

    return 0;
}
