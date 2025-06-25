#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack implementation for operators
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *st) {
    st->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *st) {
    return st->top == -1;
}

// Push an element onto the stack
void push(Stack *st, char c) {
    if (st->top < MAX - 1) {
        st->data[++(st->top)] = c;
    }
}

// Pop an element from the stack
char pop(Stack *st) {
    if (!isEmpty(st)) {
        return st->data[(st->top)--];
    }
    return '\0'; // Return null character if stack is empty
}

// Get the top element of the stack
char peek(Stack *st) {
    if (!isEmpty(st)) {
        return st->data[st->top];
    }
    return '\0'; // Return null character if stack is empty
}

// Determine precedence of operators
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

// Convert infix to postfix
void infixToPostfix(const char *infix, char *postfix) {
    Stack st;
    initStack(&st);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If the character is an operand, add it to the result
        if (isalpha(c)) {
            postfix[j++] = c;
        }
        // If the character is '(', push it onto the stack
        else if (c == '(') {
            push(&st, c);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (c == ')') {
            while (!isEmpty(&st) && peek(&st) != '(') {
                postfix[j++] = pop(&st);
            }
            if (!isEmpty(&st)) {
                pop(&st); // Remove '(' from the stack
            }
        }
        // If the character is an operator
        else {
            while (!isEmpty(&st) && prec(c) <= prec(peek(&st))) {
                postfix[j++] = pop(&st);
            }
            push(&st, c);
        }
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(&st)) {
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0'; // Null-terminate the result
}

int main() {
    const char *infix = "(a-b/c)*(a/k-l)";
    char postfix[MAX];

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
