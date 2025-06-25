#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>  // Required for strlen()

#define MAX 100

// Stack implementation using array
int stack[MAX];
int top = -1;

// Push element onto stack
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop element from stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// Prefix evaluation function
int prefixEvaluation(char* s) {
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (isdigit(s[i])) {  // Check if the character is a digit
            push(s[i] - '0');
        } else {
            int op1 = pop();
            int op2 = pop();
            switch (s[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    push(op1 / op2);
                    break;
                case '^':
                    push(pow(op1, op2));
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", s[i]);
                    exit(1);
            }
        }
    }
    return pop();
}

int main() {
    char expression[] = "-+7*45+20";
    printf("Result: %d\n", prefixEvaluation(expression));
    return 0;
}
