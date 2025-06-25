#include <iostream>
using namespace std;

class Node {
public:
    int n;
    Node *pre, *next;
};

class DBList {
    Node *head, *list;
public:
    DBList() {
        head = nullptr; // Initialize head as nullptr
    }
    void input();
    void display();
    void insert();
    void del();
};

void DBList::input() {
    Node *temp;
    int value;
    while (true) {
        cout << "\nEnter a number (0 for end): ";
        cin >> value;
        if (value == 0) break; // Stop input on entering 0

        Node *newNode = new Node();
        newNode->n = value;
        newNode->next = nullptr;
        newNode->pre = nullptr;

        if (head == nullptr) { // If the list is empty
            head = newNode;
            list = head;
        } else {
            list->next = newNode;
            newNode->pre = list;
            list = list->next;
        }
    }
}

void DBList::display() {
    if (head == nullptr) {
        cout << "\nThe list is empty!";
        return;
    }

    list = head;
    cout << "\nDisplaying list in forward order:";
    while (list != nullptr) {
        cout << "\n" << list->n;
        if (list->next == nullptr) break;
        list = list->next;
    }

    cout << "\nDisplaying list in reverse order:";
    while (list != nullptr) {
        cout << "\n" << list->n;
        list = list->pre;
    }
}

void DBList::insert() {
    Node *temp;
    int key;
    list = head;
    temp = new Node();
    cout << "Value of new item? ";
    cin >> temp->n;
    cout << "Value of key item? (type 0 if inserting at the end) ";
    cin >> key;

    if (head == nullptr) { // If list is empty
        head = temp;
        head->pre = nullptr;
        head->next = nullptr;
        return;
    }

    if (head->n == key) { // Insert at the head
        temp->next = head;
        head->pre = temp;
        head = temp;
        head->pre = nullptr;
    } else { // Insert after a specific key
        while (list != nullptr && list->n != key) {
            list = list->next;
        }
        if (list == nullptr) { // If key not found, insert at the end
            list = head;
            while (list->next != nullptr) {
                list = list->next;
            }
            list->next = temp;
            temp->pre = list;
            temp->next = nullptr;
        } else { // Insert in the middle
            temp->next = list->next;
            if (list->next != nullptr) {
                list->next->pre = temp;
            }
            list->next = temp;
            temp->pre = list;
        }
    }
}

void DBList::del() {
    int key;
    cout << "Value to delete? ";
    cin >> key;

    if (head == nullptr) { // If list is empty
        cout << "List is empty!";
        return;
    }

    list = head;

    if (head->n == key) { // Deleting the head node
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->pre = nullptr;
        }
        delete temp;
    } else {
        while (list != nullptr && list->n != key) {
            list = list->next;
        }

        if (list == nullptr) { // If key not found
            cout << "Item not found!";
        } else { // Key found, delete node
            Node *temp = list;
            if (list->pre != nullptr) {
                list->pre->next = list->next;
            }
            if (list->next != nullptr) {
                list->next->pre = list->pre;
            }
            delete temp;
        }
    }
}

int main() {
    int choice;
    DBList l;

    do {
        cout << "\n\tM E N U";
        cout << "\n1. Create a linked list";
        cout << "\n2. Display the list";
        cout << "\n3. Insert an item into the list";
        cout << "\n4. Delete an item";
        cout << "\n5. Exit";
        cout << "\nSelect your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l.input();
                break;
            case 2:
                l.display();
                break;
            case 3:
                l.insert();
                break;
            case 4:
                l.del();
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 5);

    return 0;
}
