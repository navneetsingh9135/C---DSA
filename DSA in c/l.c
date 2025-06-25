#include <stdio.h>
#include <stdlib.h>

struct Node {
    int n;
    struct Node *next;
};

struct Linkedlist {
    struct Node *head, *list;
};

void initLinkedList(struct Linkedlist *l) {
    l->head = l->list = (struct Node *)malloc(sizeof(struct Node));
}

void input(struct Linkedlist *l) {
    for (;;) {
        printf("\nEnter a no. '0 for end' ");
        scanf("%d", &l->list->n);
        if (l->list->n == 0) {
            l->list->next = NULL;
            break;
        }
        l->list->next = (struct Node *)malloc(sizeof(struct Node));
        l->list = l->list->next;
    }
}

void display(struct Linkedlist *l) {
    l->list = l->head;
    while (l->list->next != NULL) {
        printf("\n%d", l->list->n);
        l->list = l->list->next;
    }
}

int main() {
    struct Linkedlist l;
    initLinkedList(&l);
    input(&l);
    display(&l);
    return 0;
}
