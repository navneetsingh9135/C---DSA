#include <stdio.h>
#include <stdlib.h>

struct polyterm {
    int coeff;
    int exp;
    struct polyterm *next;
};
typedef struct polyterm node;

// Function to insert a term into the polynomial
void insert(node **head, int coeff, int exp) {
    node *n = (node *)malloc(sizeof(node));
    n->coeff = coeff;
    n->exp = exp;
    n->next = *head;
    *head = n;
}

// Function to add two polynomials
node *add(node *head1, node *head2) {
    node *result = NULL;
    node **lastPtrRef = &result;

    while (head1 != NULL && head2 != NULL) {
        if (head1->exp > head2->exp) {
            *lastPtrRef = head1;
            head1 = head1->next;
        } else if (head1->exp < head2->exp) {
            *lastPtrRef = head2;
            head2 = head2->next;
        } else {
            head1->coeff += head2->coeff;
            if (head1->coeff != 0) {
                *lastPtrRef = head1;
                head1 = head1->next;
            }
            head2 = head2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    if (head1 != NULL) {
        *lastPtrRef = head1;
    } else {
        *lastPtrRef = head2;
    }

    return result;
}

// Function to display a polynomial
void display(node *head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    while (head != NULL) {
        if (head->coeff > 0 && head != head) {
            printf(" + ");
        }
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    // Example polynomials
    insert(&poly1, 4, 3);
    insert(&poly1, 3, 2);
    insert(&poly1, 2, 1);

    insert(&poly2, 5, 3);
    insert(&poly2, 6, 2);
    insert(&poly2, 7, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    result = add(poly1, poly2);

    printf("Sum: ");
    display(result);

    return 0;
}
