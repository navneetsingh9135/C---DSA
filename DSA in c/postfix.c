#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // For pow() function

#define MAX 100

// Define a stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* st) {
    st->top = -1;
}

// Push an element onto the stack
void push(struct Stack* st, int value) {
    if (st->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    st->arr[++(st->top)] = value;
}

// Pop an element from the stack
int pop(struct Stack* st) {
    if (st->top == -1) {
        printf("No element to pop\n");
        return -1; // Indicates error
    }
    return st->arr[(st->top)--];
}

// Peek at the top element of the stack
int peek(struct Stack* st) {
    if (st->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return st->arr[st->top];
}

// Evaluate postfix expression
int postfixEvaluation(char* s) {
    struct Stack st;
    initStack(&st);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            push(&st, s[i] - '0');  // Push numeric characters as integers
        } else {
            int op1 = pop(&st);
            int op2 = pop(&st);

            switch (s[i]) {
                case '+':
                    push(&st, op2 + op1);
                    break;
                case '-':
                    push(&st, op2 - op1);
                    break;
                case '*':
                    push(&st, op2 * op1);
                    break;
                case '/':
                    push(&st, op2 / op1);
                    break;
                case '^':
                    push(&st, pow(op2, op1));
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", s[i]);
                    break;
            }
        }
    }
    return peek(&st);  // The result is the top of the stack
}

int main() {
    char s[] = "46+2/5*7+";
    printf("Result: %d\n", postfixEvaluation(s));
    return 0;
}
