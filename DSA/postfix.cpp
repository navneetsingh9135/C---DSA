#include <iostream>
#include <stack>
#include <cmath>  // For pow() function
using namespace std;

int postfixEvaluation(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');  // Push numeric characters as integers
        } else {                            
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i]) {
                case '+':
                    st.push(op2 + op1);  // Correct order
                    break;
                case '-':
                    st.push(op2 - op1);  // Correct order
                    break;
                case '*':
                    st.push(op2 * op1);  // Correct order
                    break;
                case '/':
                    st.push(op2 / op1);  // Correct order
                    break;
                case '^':
                    st.push(pow(op2, op1));  // Correct order
                    break;
                default:
                    cout << "Invalid operator encountered: " << s[i] << endl;
                    break;
            }
        }
    }
    return st.top();  // The result is the top of the stack
}

int main() {
    string s = "46+2/5*7+";
    cout << "Result: " << postfixEvaluation(s) << endl;
    return 0;
}
