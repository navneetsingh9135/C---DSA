#include <iostream>
using namespace std;

class Node {
public:
    int n;
    Node* next;
};

class Linkedlist {
    Node *head, *list;
public:
    Linkedlist() { head = list = nullptr; }
    void input();
    void display();
    void insert();
    void del();
};

void Linkedlist::input() {
    Node* newNode;
    while (true) {
        newNode = new Node;
        cout << "\nEnter a no. '0 for end' ";
        cin >> newNode->n;
        if (newNode->n == 0) {
            if (list != nullptr)
                list->next = head;  // Make it circular
            delete newNode;  // Deleting last allocated node
            break;
        }
        newNode->next = head;  // Point to head to make circular
        if (head == nullptr) {
            head = newNode;
        } else {
            list->next = newNode;
        }
        list = newNode;
    }
}

void Linkedlist::display() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    list = head;
    do {
        cout << "\n" << list->n;
        list = list->next;
    } while (list != head);
}

void Linkedlist::insert() {
    Node* temp = new Node;
    int key;
    cout << "Value of new item? ";
    cin >> temp->n;
    cout << "Value of key item? (type 0 if last) ";
    cin >> key;

    list = head;
    if (key == 0) {  // Insert at the end
        if (!head) {
            head = temp;
            temp->next = head;  // Point to self in an empty list
        } else {
            while (list->next != head)
                list = list->next;
            list->next = temp;
            temp->next = head;
        }
    } else if (head->n == key) {  // Insert at the head
        temp->next = head;
        while (list->next != head)
            list = list->next;
        list->next = temp;
        head = temp;
    } else {  // Insert in the middle or end
        while (list->next != head && list->next->n != key)
            list = list->next;
        if (list->next->n == key) {
            temp->next = list->next;
            list->next = temp;
        } else {
            cout << "Key not found!\n";
            delete temp;  // Clean up if key is not found
        }
    }
}

void Linkedlist::del() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp;
    int key;
    cout << "Value to delete? ";
    cin >> key;

    list = head;
    if (head->n == key) {  // Deleting head node
        while (list->next != head)
            list = list->next;
        if (list == head) {  // Only one element
            delete head;
            head = nullptr;
        } else {
            list->next = head->next;
            delete head;
            head = list->next;
        }
    } else {  // Deleting non-head node
        while (list->next != head && list->next->n != key)
            list = list->next;
        if (list->next->n == key) {
            temp = list->next;
            list->next = temp->next;
            delete temp;
        } else {
            cout << "Key not found!\n";
        }
    }
}

int main() {
    int choice;
    Linkedlist l;
    do {
        cout << "\n\tM E N U";
        cout << "\n1. Creating Circular linked list";
        cout << "\n2. Display the list";
        cout << "\n3. Inserting item to the list";
        cout << "\n4. Deleting an item";
        cout << "\n5. Exit";
        cout << "\nSelect your choice: ";
        cin >> choice;
        if (choice == 1) l.input();
        if (choice == 2) l.display();
        if (choice == 3) l.insert();
        if (choice == 4) l.del();
    } while (choice != 5);

    return 0;
}
