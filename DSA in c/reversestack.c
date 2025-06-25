#include <stdio.h>
#define MAX 100

// Stack structure
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack* st) {
    st->top = -1;
}

// Check if stack is empty
int isEmpty(Stack* st) {
    return st->top == -1;
}

// Push element onto stack
void push(Stack* st, int ele) {
    if (st->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    st->arr[++(st->top)] = ele;
}

// Pop element from stack
int pop(Stack* st) {
    if (isEmpty(st)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return st->arr[(st->top)--];
}

// Access the top element
int top(Stack* st) {
    if (!isEmpty(st)) {
        return st->arr[st->top];
    }
    return -1; // Return -1 if stack is empty
}

// Function to insert an element at the bottom of the stack
void insertAtBottom(Stack* st, int ele) {
    if (isEmpty(st)) {
        push(st, ele);
        return;
    }
    int topele = pop(st);
    insertAtBottom(st, ele);
    push(st, topele);
}

// Function to reverse the stack
void reverse(Stack* st) {
    if (isEmpty(st)) {
        return;
    }
    int ele = pop(st);
    reverse(st);
    insertAtBottom(st, ele);
}

// Main function
int main() {
    Stack st;
    initStack(&st);

    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);

    reverse(&st);

    while (!isEmpty(&st)) {
        printf("%d\n", top(&st));
        pop(&st);
    }

    return 0;
}
