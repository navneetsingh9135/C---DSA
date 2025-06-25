#include<iostream>
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

void insertAtHead(node *&head, int val) {
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val) {
    node *n = new node(val);
    if(head == NULL) {
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Recursive function to reverse the linked list
node* reverseRecursive(node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// Iterative function to reverse the linked list
node* reverse(node* head) {
    node* prev = NULL;
    node* curr = head;
    node* next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    
    cout << "Original List: ";
    display(head);
    
    head = reverse(head);
    cout << "Reversed List (Iterative): ";
    display(head);
    
    head = reverseRecursive(head);
    cout << "Reversed List (Recursive): ";
    display(head);

    return 0;
}
