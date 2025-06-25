#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert at the beginning
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

    // Insert at the end
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

    // Delete a node
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
            head = temp->next; // Node to be deleted is the head
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Display the list in reverse order
    void displayReverse() {
        Node* temp = head;
        if (temp == nullptr) return;

        // Go to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Traverse backward using prev pointer
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;
    
    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    std::cout << "List: ";
    dll.display();

    std::cout << "List in reverse: ";
    dll.displayReverse();

    dll.deleteNode(20);
    std::cout << "After deleting 20: ";
    dll.display();

    return 0;
}
