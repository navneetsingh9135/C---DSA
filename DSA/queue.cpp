#include <iostream>
using namespace std;

class queue {
    int* arr;
    int front;
    int back;
    int n; // size of the queue

public:
    queue(int size) {
        n = size;
        arr = new int[n];
        front = -1;
        back = -1; 
    }

    void push(int x) {
        if (back == n - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1) {
            front++;
        }
    }

    void pop() {
        if (front == -1 || front > back) {
            cout << "No element in queue" << endl;
            return;
        }
        front++;
    }

    int peek() {
        if (front == -1 || front > back) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        if (front == -1 || front > back) {
            return true;
        }
        return false;
    }

    ~queue() { // Destructor to free memory
        delete[] arr;
    }
};

int main() {
    queue q(5); // Provide a size to the queue

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout << q.peek() << endl;  // Outputs the front element
    q.pop();
    cout << q.peek() << endl;  // Outputs the next front element
    q.pop();
    cout << q.peek() << endl;  // Outputs the next front element
    q.pop();
    cout << q.empty() << endl;  // Check if queue is empty

    return 0;
}
