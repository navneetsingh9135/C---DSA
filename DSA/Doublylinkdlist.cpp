#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node* &head, int val) {
    if (head == NULL) { 
        insertAtHead(head, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int length(node* head) {
    int l = 0;
    node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        l++;
    }
    return l;
}

// Function to find the intersection point (data) between two linked lists
int intersection(node* &head1, node* &head2) {
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node* ptr1;
    node* ptr2;

    if (l1 > l2) {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    } else {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    // Move the longer list's pointer by 'd' steps
    while (d--) {
        ptr1 = ptr1->next;
        if (ptr1 == NULL) return -1;
    }

    // Traverse both lists until we find the intersection point
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1->data;  // Return the intersection node's data
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;  // No intersection
}

// Function to link two lists at a specific position in the first list
void intersect(node* &head1, node* &head2, int pos) {
    node* temp1 = head1;
    while (--pos && temp1 != NULL) {
        temp1 = temp1->next;
    }

    node* temp2 = head2;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    // Linking the end of the second list to the specific position of the first list
    temp2->next = temp1;
    if (temp1 != NULL) {
        temp1->prev = temp2;
    }
}

void deleteAtHead(node* &head) {
    node* toDelete = head;
    if (head == NULL) return;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete toDelete;
}

void deletion(node* &head, int pos) {
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;
    while (temp != NULL && count != pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) return;  // If position exceeds list length

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main() {
    node* head1 = NULL;
    node* head2 = NULL;

    // Insert elements into the first list
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);

    // Insert elements into the second list
    insertAtTail(head2, 9);
    insertAtTail(head2, 10);

    // Intersect the second list with the first list at position 3
    intersect(head1, head2, 3);

    // Display both lists
    display(head1);
    display(head2);

    // Find the intersection point
    int intersectData = intersection(head1, head2);
    if (intersectData != -1) {
        cout << "Intersection point is at node with data: " << intersectData << endl;
    } else {
        cout << "No intersection point found." << endl;
    }

    return 0;
}
