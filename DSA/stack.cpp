#include <iostream>
using namespace std;

class stack {
    int* arr;
    int top;
    int n; // size of the stack
public:
    stack(int size) {
        n = size;
        arr = new int[n];
        top = -1;
    }

    void push(int x) {
        if (top == n - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    int Top() {
        if (top == -1) {
            cout << "No element in stack" << endl;
            return -1;  // Handle case when there is no element
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

    ~stack() {
        delete[] arr; // Clean up dynamically allocated memory
    }
};

int main() {
    stack st(5); // Create a stack of size 5
    st.push(1);
    st.push(2);
    st.push(3);
    
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    
    st.pop();
    st.pop();
    st.pop(); // This will output "No element to pop"
    
    cout << (st.empty() ? "Stack is empty" : "Stack is not empty") << endl;

    return 0;
}
