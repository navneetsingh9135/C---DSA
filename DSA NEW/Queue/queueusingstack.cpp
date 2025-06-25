#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {}
    
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    
    cout << "Front element: " << q.peek() << endl; // Output: 1
    cout << "Popped element: " << q.pop() << endl; // Output: 1
    cout << "Front element: " << q.peek() << endl; // Output: 2
    
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: No
    
    q.pop();
    q.pop();
    
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: Yes
    
    return 0;
}