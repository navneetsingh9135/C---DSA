#include<iostream>
#include<stack>  // Add this to include stack
using namespace std;

class que {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s1.empty() && s2.empty()) {
            cout << "\nQueue is empty";
            return -1;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {  // Change this from int32_t to int
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop();
    q.push(5);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop()<<endl;
    return 0;
}
