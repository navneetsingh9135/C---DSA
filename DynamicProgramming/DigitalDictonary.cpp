#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *next[26]; // Array to store links to the next nodes
    bool end;       // To mark the end of a word

    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL; // Initialize all links to NULL
        }
        end = false; // Word ending is false by default
    }
};

class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node(); // Initialize root
    }

    void insert(string &s) {
        Node *it = root; // Start from the root
        for (auto c : s) {
            if (!it->next[c - 'a']) { // If no node exists for this character
                it->next[c - 'a'] = new Node(); // Create a new node
            }
            it = it->next[c - 'a']; // Move to the next node
        }
        it->end = true; // Mark the end of the word
    }

    void find(string &s) {
        Node *it = root; // Start from the root
        for (auto c : s) {
            if (!it->next[c - 'a']) { // If no node exists for this prefix
                cout << "No Suggestions\n";
                insert(s); // Insert the word into the Trie
                return;
            }
            it = it->next[c - 'a']; // Move to the next node
        }

        vector<string> res;
        printAll(it, s, res, ""); // Find all suggestions starting with the prefix
        for (auto suggestion : res) {
            cout << s << suggestion << "\n"; // Print the suggestions
        }
    }

    void printAll(Node *it, string &prefix, vector<string> &res, string cur) {
        if (it == NULL) return; // Base case: Stop if node is NULL
        if (it->end) {          // If a word ends here, add it to the results
            res.push_back(cur);
        }
        for (int i = 0; i < 26; i++) { // Explore all possible characters
            if (it->next[i]) { // If a node exists for this character
                printAll(it->next[i], prefix, res, cur + char('a' + i));
            }
        }
    }
};

int main() {
    Trie t;
    int n;
    cin >> n; // Number of words to insert
    vector<string> a(n);
    for (auto &i : a) {
        cin >> i;
        t.insert(i); // Insert each word into the Trie
    }
    int q;
    cin >> q; // Number of queries
    while (q--) {
        string s;
        cin >> s; // Query string
        t.find(s); // Find suggestions for the query string
    }
    return 0;
}
