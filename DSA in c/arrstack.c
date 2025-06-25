#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocatioan

// Define a struct for the stack
struct Stack { 
    int* arr;
    int top;
    int n; // size of the stack
};

// Function to initialize the stack
void initStack(struct Stack* st, int size) {
    st->n = size;
    st->arr = (int*)malloc(size * sizeof(int)); // Dynamically allocate memory
    st->top = -1;
}

// Function to push an element to the stack
void push(struct Stack* st, int x) {
    if (st->top == st->n - 1) {  // Check for stack overflow
        printf("Stack overflow\n");
        return;
    }
    st->top++;  
    st->arr[st->top] = x;
}

// Function to pop an element from the stack
void pop(struct Stack* st) {
    if (st->top == -1) {  // Check for stack underflow
        printf("No element to pop\n");
        return;
    }
    st->top--;
}

// Function to get the top element of the stack
int Top(struct Stack* st) {
    if (st->top == -1) {  // Check if the stack is empty
        printf("No element in stack\n");
        return -1;  // Return a default value for an empty stack
    }
    return st->arr[st->top];
}

// Function to check if the stack is empty
int empty(struct Stack* st) {
    return st->top == -1;
}

// Function to free the dynamically allocated memory
void freeStack(struct Stack* st) {
    free(st->arr);
}

// Main function
int main() {
    struct Stack st;
    initStack(&st, 5);  // Create a stack of size 5
    
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    
    printf("%d\n", Top(&st));  // Output: 3
    pop(&st);
    
    printf("%d\n", Top(&st));  // Output: 2
    pop(&st);
    pop(&st);
    
    pop(&st);  // This will output "No element to pop"
    
    printf("%s\n", empty(&st) ? "Stack is empty" : "Stack is not empty");  // Output: Stack is empty
    
    freeStack(&st);  // Free dynamically allocated memory
    
    return 0;
}
