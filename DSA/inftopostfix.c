#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Define a stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++s->top] = c;
}

// Function to pop an element from the stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to get the top element of the stack
char peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[s->top];
}

// Function to get the precedence of an operator
int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char* s, char* result) {
    Stack st;
    initStack(&st);
    int k = 0; // Index for the result string

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // If the character is an operand, add it to the result
        if (isalpha(c)) {
            result[k++] = c;
        }
        // If the character is '(', push it onto the stack
        else if (c == '(') {
            push(&st, c);
        }
        // If the character is ')', pop and add to the result until '(' is encountered
        else if (c == ')') {
            while (!isEmpty(&st) && peek(&st) != '(') {
                result[k++] = pop(&st);
            }
            if (!isEmpty(&st)) {
                pop(&st); // Remove '(' from the stack
            }
        }
        // If the character is an operator
        else {
            while (!isEmpty(&st) && prec(c) <= prec(peek(&st))) {
                result[k++] = pop(&st);
            }
            push(&st, c);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&st)) {
        result[k++] = pop(&st);
    }
    result[k] = '\0'; // Null-terminate the result string
}

int main() {
    char expression[] = "(a-b/c)*(a/k-l)";
    char result[MAX];
    infixToPostfix(expression, result);
    printf("Postfix expression: %s\n", result);
    return 0;
}
