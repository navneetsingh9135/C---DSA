#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    string s;g
    cin >> s;
    stack<char> st;
    bool ans = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            st.push(s[i]);
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            // If top is '(' immediately after ')', it means there's nothing between them
            if (st.top() == '(') {
                ans = true;  // Redundant parentheses found
            }
            // Pop elements until finding '('
            while (!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')) {
                st.pop();
            }
            // Pop the opening parenthesis '('
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
        }
    }

    cout << (ans ? "Yes" : "No") << endl;  // Output whether redundant parentheses are found

    return 0;
}
