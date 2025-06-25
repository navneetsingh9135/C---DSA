#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}

int rear(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->rear];
}

typedef struct Stack {
    int N;
    Queue* q1;
    Queue* q2;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    stack->N = 0;
    return stack;
}

void push(Stack* stack, int val) {
    enqueue(stack->q1, val);
    stack->N++;
}

void pop(Stack* stack) {
    if (isEmpty(stack->q1))
        return;

    while (stack->q1->size != 1) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    dequeue(stack->q1);
    stack->N--;

    Queue* temp = stack->q1;
    stack->q1 = stack->q2;  
    stack->q2 = temp;
}

int top(Stack* stack) { 
    if (isEmpty(stack->q1))
        return -1;

    while (stack->q1->size != 1) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int ans = front(stack->q1);
    enqueue(stack->q2, dequeue(stack->q1));

    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;   
    return ans;
}

int size(Stack* stack) {
    return stack->N;
}

int main() {
    Stack* st = createStack(1000);
    push(st, 1);
    push(st, 2);
    push(st, 3);
    push(st, 4);
    printf("%d\n", top(st));
    pop(st);
    printf("%d\n", top(st));
    pop(st);
    printf("%d\n", top(st));
    pop(st);
    printf("%d\n", top(st));
    pop(st);
    printf("%d\n", top(st));
    pop(st);
    printf("%d\n", size(st));

    return 0;
}
