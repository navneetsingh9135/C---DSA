#include <iostream>
using namespace std;

class MyStack {
    int* arr;
    int top;
    int n; // size of the stack

public:
    MyStack(int size = 100) { // Default size of 100
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
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

    ~MyStack() { // Destructor to avoid memory leaks
        delete[] arr;
    }
};

int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;
    return 0;
}
