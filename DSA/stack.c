#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
typedef struct stack {
    int* arr;  // Pointer to the stack array
    int top;   // Index of the top element
    int n;     // Size of the stack
} stack;

// Function to initialize the stack
void initStack(stack* st, int size) {
    st->n = size;
    st->arr = (int*)malloc(size * sizeof(int));
    st->top = -1;
}

// Function to push an element onto the stack
void push(stack* st, int x) {
    if (st->top == st->n - 1) {
        printf("Stack overflow\n");
        return;
    }
    st->top++;
    st->arr[st->top] = x;
}

// Function to pop an element from the stack
void pop(stack* st) {
    if (st->top == -1) {
        printf("No element to pop\n");
        return;
    }
    st->top--;
}

// Function to get the top element of the stack
int Top(stack* st) {
    if (st->top == -1) {
        printf("No element in stack\n");
        return -1;  // Return -1 if the stack is empty
    }
    return st->arr[st->top];
}

// Function to check if the stack is empty
int empty(stack* st) {
    return st->top == -1;
}

// Function to clean up the stack
void freeStack(stack* st) {
    free(st->arr);  // Free dynamically allocated memory
}

int main() {
    stack st;
    initStack(&st, 5);  // Create a stack of size 5

    // Push elements onto the stack
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);

    printf("%d\n", Top(&st)); // Print the top element
    pop(&st);
    printf("%d\n", Top(&st)); // Print the top element after popping

    pop(&st);
    pop(&st);
    pop(&st); // Attempt to pop from an empty stack

    printf("%s\n", empty(&st) ? "Stack is empty" : "Stack is not empty");

    freeStack(&st); // Clean up the stack
    return 0;
}
