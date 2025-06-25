#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int n;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* list;
} Linkedlist;

void input(Linkedlist* l) {
    for (;;) {
        printf("\nEnter a no. '0 for end' ");
        scanf("%d", &l->list->n);
        if (l->list->n == 0) {
            l->list->next = 0;
            break;
        }
        l->list->next = (Node*)malloc(sizeof(Node));
        l->list = l->list->next;
    }
}

void display(Linkedlist* l) {
    int count = 0;
    Node* temp = l->head;
    while (temp->next != 0) {
        if (temp->n % 2 == 0) {
            count++;
            printf("\n%d", temp->n);
        }
        temp = temp->next;
    }
    printf("\nNo of even nos=%d", count);
}

int main() {
    Linkedlist l;
    l.head = (Node*)malloc(sizeof(Node));
    l.list = l.head;
    input(&l);
    display(&l);
    return 0;
}