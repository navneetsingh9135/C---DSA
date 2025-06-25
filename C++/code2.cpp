#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is alphanumeric
bool isAlphaNum(char ch) {
    return (ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z');
}

// Function to check if a string is a palindrome
bool isPalindrome(string s) {
    int st = 0, end = s.length() - 1;
    while (st < end) {
        // Skip non-alphanumeric characters from the start
        if (!isAlphaNum(s[st])) {
            st++;
            continue;
        }
        // Skip non-alphanumeric characters from the end
        if (!isAlphaNum(s[end])) {
            end--;
            continue;
        }
        // Compare characters (case-insensitive)
        if (tolower(s[st]) != tolower(s[end])) {
            return false; // Not a palindrome
        }
        st++;
        end--;
    }
    return true; // It's a palindrome
}

int main() {
    string str = "A man, a plan, a canal: Panama";
    if (isPalindrome(str)) {
        cout << "\"" << str << "\" is a palindrome!" << endl;
    } else {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }
    return 0;
}
