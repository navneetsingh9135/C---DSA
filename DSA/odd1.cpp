#include <iostream>
using namespace std;

class Node {
    int n;
    Node *next;
    friend class Linkedlist;  // Declare Linkedlist as a friend class so it can access private members of Node
};

class Linkedlist {
    Node *head, *list;

public:
    Linkedlist() { head = list = new Node; }
    void input();
    void display();
};

// Function to take input
void Linkedlist::input() {
    for (;;) {
        cout << "\nEnter a number (0 to end): ";
        cin >> list->n;
        if (list->n == 0) {
            list->next = 0;
            break;
        }
        list->next = new Node;
        list = list->next;
    }
}

// Function to display odd numbers and count them
void Linkedlist::display() {
    int count = 0;
    list = head;
    while (list->next != 0) {
        if (list->n % 2 != 0) {  // Check for odd numbers
            count++;
            cout << "\n" << list->n;  // Print the odd number
        }
        list = list->next;
    }
    cout << "\nNumber of odd numbers = " << count;
}

int main() {
    Linkedlist l;
    l.input();
    l.display();
    return 0;
}
