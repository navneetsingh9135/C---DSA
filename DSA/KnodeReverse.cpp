#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

node* kReverse(node* head, int k){
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;
    while(current != NULL && count < k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(next != NULL){
        head->next = kReverse(next, k);
    }
    return prev;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    display(head);
    int k = 3;
    head = kReverse(head, k);
    display(head);
    
    return 0;
}