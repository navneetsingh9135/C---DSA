#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    ~DoublyLinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteNode(int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Node not found.\n";
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void displayReverse() {
        Node* temp = head;
        if (temp == nullptr) return;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert at the beginning\n";
        std::cout << "2. Insert at the end\n";
        std::cout << "3. Delete a node\n";
        std::cout << "4. Display list\n";
        std::cout << "5. Display list in reverse\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert at the beginning: ";
                std::cin >> value;
                dll.insertAtBeginning(value);
                break;

            case 2:
                std::cout << "Enter value to insert at the end: ";
                std::cin >> value;
                dll.insertAtEnd(value);
                break;

            case 3:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                dll.deleteNode(value);
                break;

            case 4:
                std::cout << "List: ";
                dll.display();
                break;

            case 5:
                std::cout << "List in reverse: ";
                dll.displayReverse();
                break;

            case 6:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
