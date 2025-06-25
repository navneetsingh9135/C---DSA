#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        // Constructor
    }
    
    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Push new element into q1
        q1.push(x);
        
        // Move all elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        if (q1.empty()) {
            cout << "Stack underflow!" << endl;
            return -1; // Indicating error
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Indicating error
        }
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl; // Should print 30

    cout << "Popped element: " << stack.pop() << endl; // Should print 30
    cout << "Top element: " << stack.top() << endl; // Should print 20

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Should print No

    stack.pop();
    stack.pop();

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}
