#include <iostream>
using namespace std;

class stack {
    int* arr;
    int top;
    int n; // size of the stack

public:
    stack(int size = 100) { // constructor with default size 100
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
            return -1; // Returning an invalid value
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

    ~stack() { // Destructor to avoid memory leak
        delete[] arr;
    }
};

int main() {
    stack st;
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
