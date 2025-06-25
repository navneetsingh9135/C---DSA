#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL; 
    }
};

class queue {
    node* front;
    node* back;
    
    public:
    queue() {
        front = NULL;
        back = NULL;
    }

    void push(int x) {
        node* n = new node(x);
        if (front == NULL) {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop() {
        if (front == NULL) {
            cout << "Queue underflow" << endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek() {
        if (front == NULL) {
            cout << "No element in queue" << endl;
            return -1; // Returning a default value when the queue is empty
        }
        return front->data;
    }

    bool empty() {
        return front == NULL;
    }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout << q.peek() << endl;  // Outputs 1
    q.pop();
    
    cout << q.peek() << endl;  // Outputs 2
    q.pop();
    
    cout << q.peek() << endl;  // Outputs 3
    q.pop();
    
    cout << q.peek() << endl;  // Outputs 4
    q.pop();
    
    cout << q.empty() << endl;  // Outputs 1 (true, as the queue is now empty)

    return 0;
}
