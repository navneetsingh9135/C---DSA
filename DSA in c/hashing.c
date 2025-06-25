#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Hashing {
    Node** hashtable;
    int buckets;
} Hashing;

// Function to create a new Hashing structure
Hashing* createHashing(int size) {
    Hashing* h = (Hashing*)malloc(sizeof(Hashing));
    h->buckets = size;
    h->hashtable = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        h->hashtable[i] = NULL;
    }
    return h;
}

// Function to calculate hash value
int hashvalue(Hashing* h, int key) {
    return key % h->buckets;
}

// Function to add a key to the hash table
void addKey(Hashing* h, int key) {
    int index = hashvalue(h, key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = h->hashtable[index];
    h->hashtable[index] = newNode;
}

// Function to search for a key in the hash table
Node* searchKey(Hashing* h, int key) {
    int index = hashvalue(h, key);
    Node* current = h->hashtable[index];
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a key from the hash table
void deleteKey(Hashing* h, int key) {
    int index = hashvalue(h, key);
    Node* current = h->hashtable[index];
    Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key %d is not present inside the hashtable\n", key);
        return;
    }

    if (prev == NULL) {
        h->hashtable[index] = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Key %d is deleted\n", key);
}

// Function to free the hash table
void freeHashing(Hashing* h) {
    for (int i = 0; i < h->buckets; i++) {
        Node* current = h->hashtable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(h->hashtable);
    free(h);
}

int main() {
    Hashing* h = createHashing(10);
    addKey(h, 5);
    addKey(h, 9);
    addKey(h, 3);
    deleteKey(h, 3);
    deleteKey(h, 3);
    deleteKey(h, 9);
    deleteKey(h, 5);
    freeHashing(h); // Free allocated memory
    return 0;
}
