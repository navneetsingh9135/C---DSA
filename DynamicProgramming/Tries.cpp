#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    class node {
    public:
        bool end;
        node* next[26];
        node() {
            end = false;
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    };

    node* trie;

    Trie() {
        trie = new node();
    }

    void insert(string word) {
        int i = 0;
        node* it = trie;
        while (i < word.size()) { 
            if (it->next[word[i] - 'a'] == NULL) {
                it->next[word[i] - 'a'] = new node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true; // This should set the end of the word
    }

    bool search(string word) {
        int i = 0;
        node* it = trie;
        while (i < word.size()) {
            if (it->next[word[i] - 'a'] == NULL) {
                return false;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};

int main() {
    Trie* myTrie = new Trie(); // Use pointer and correct object initialization
    vector<string> words = {"ayush", "daasi"};
    for (auto w : words) {
        myTrie->insert(w);
    }

    if (myTrie->search("madhav")) {
        cout << "Madhav found\n";
    } else {
        cout << "Madhav does not exist\n";
    }

    if (myTrie->search("ayush")) {
        cout << "Ayush found\n";
    } else {
        cout << "Ayush does not exist\n";
    }

    return 0;
}
