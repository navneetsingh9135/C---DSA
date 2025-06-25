#include <bits/stdc++.h>
using namespace std;

// Trie Node Class
class TrieNode {
public:
    TrieNode* next[2];
    TrieNode() {
        next[0] = NULL;
        next[1] = NULL;
    }
};

// Function to build the Trie
TrieNode* buildTrie(vector<int>& a) {
    TrieNode* root = new TrieNode();
    for (int num : a) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (cur->next[bit] == NULL) {
                cur->next[bit] = new TrieNode();
            }
            cur = cur->next[bit];
        }
    }
    return root;
}

// Function to find the maximum XOR value
int helper(TrieNode* root, vector<int>& a) {
    int res = 0; 
    for (int num : a) {
        TrieNode* it = root;
        int cur_max = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite_bit = 1 - bit; // Opposite bit for maximizing XOR
            if (it->next[opposite_bit]) {
                cur_max = (cur_max << 1) | 1;
                it = it->next[opposite_bit];
            } else {
                cur_max = (cur_max << 1);
                it = it->next[bit];
            }
        }
        res = max(res, cur_max);
    }
    return res;
}

int main() {
    // Input array
    vector<int> a = {3, 10, 5, 15, 2};

    // Build Trie
    TrieNode* root = buildTrie(a);

    // Compute Maximum XOR
    int ans = helper(root, a);

    // Output Result
    cout << "Maximum XOR is: " << ans << endl;

    return 0;
}
