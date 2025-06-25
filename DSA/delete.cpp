#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert at the head
void insertAtHead(node *&head, int val) {
    node *n = new node(val);
    n->next = head;
    head = n;
}

// Function to insert at the tail
void insertAtTail(node *&head, int val) {
    node *n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

// Function to display the list
void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to search for a value in the list
bool search(node *head, int key) {
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) { // Fixed: Use == instead of =
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to delete the head node
void deleteAtHead(node *&head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    node *todelete = head;
    head = head->next;
    delete todelete;
}

// Function to delete a node by value
void deletion(node *&head, int val) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    // If the value to delete is in the head
    if (head->data == val) {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    // Traverse until the node before the one to delete
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    // If value is not found
    if (temp->next == NULL) {
        cout << "Value " << val << " not found in the list." << endl;
        return;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

// Main function
int main() {
    node *head = NULL;

    // Insert elements
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);

    // Insert at the head
    insertAtHead(head, 4);
    display(head);

    // Search for an element
    cout << "Is 4 in the list? " << (search(head, 4) ? "Yes" : "No") << endl;

    // Delete an element
    deletion(head, 3);
    display(head);

    // Delete the head
    deleteAtHead(head);
    display(head);

    // Try deleting a non-existent value
    deletion(head, 10);

    return 0;
}
