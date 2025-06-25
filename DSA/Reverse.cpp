#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *next;
    
    node(int val) {  // Fixed constructor with proper closing brace
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
    display(head);
    head = reverse(head);
    display(head);
    return 0;
}
