#include <stdio.h>
#include <stdlib.h> // Include for malloc and free

struct poly {
    int c, p;
    struct poly *next;
};

typedef struct poly node;

int main() {
    node *head, *list, *temp, *temp1;
    head = (node *) malloc(sizeof(node));
    list = head;
    
    printf("\nInput co-efficient and power (Press 0 for end):");
    while (1) {
        printf("\nC-");
        scanf("%d", &list->c);
        
        if (list->c == 0) {
            list->next = NULL;  // End the list
            break;
        }
        
        printf("\nP-");
        scanf("%d", &list->p);
        
        list->next = (node *) malloc(sizeof(node));
        list = list->next;
    }
    
    // Combine terms with the same power
    for (list = head; list != NULL && list->next != NULL; list = list->next) {
        for (temp1 = list, temp = list->next; temp != NULL; ) {
            if (list->p == temp->p) {
                list->c = list->c + temp->c;
                temp1->next = temp->next;
                free(temp);
                temp = temp1->next;
            } else {
                temp1 = temp;
                temp = temp->next;
            }
        }
    }

    // Display the result
    printf("\nResult:");
    printf("\nCo.\tPower\n");
    list = head;
    while (list != NULL) {
        printf("%d\t%d\n", list->c, list->p);
        list = list->next;
    }
    
    // Free allocated memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
