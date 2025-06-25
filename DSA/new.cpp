#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
};

class linkedlist {
    public:
    node* head;

    linkedlist() {  // Constructor to initialize the head
        head = NULL;
    }

    void insert(int value) {
        node* newnode = new node();
        newnode->data = value;
        newnode->next = head;
        head = newnode;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    linkedlist ll;
    ll.insert(10);
    ll.display();

    return 0;
}
