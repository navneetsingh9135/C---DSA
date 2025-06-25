#include <bits/stdc++.h>
using namespace std;

const int INT_SIZE = 32; // Maximum size of an integer (in bits)

class Node {
public:
    Node* next[2];

    Node() {
        next[0] = NULL;
        next[1] = NULL;
    }
};

Node* trie;

// Function to insert a number into the Trie
void insert(int num) {
    Node* it = trie;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        int cur_bit = (num >> i) & 1;
        if (!it->next[cur_bit]) {
            it->next[cur_bit] = new Node();
        }
        it = it->next[cur_bit];
    }
}

// Function to query the maximum XOR for a given number
int query(int num) {
    Node* it = trie;
    int ans = 0;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        int cur_bit = (num >> i) & 1;
        int opposite_bit = cur_bit ^ 1;
        if (it->next[opposite_bit]) {
            it = it->next[opposite_bit];
            ans |= (1 << i);
        } else {
            it = it->next[cur_bit];
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    trie = new Node();
    insert(0); // Insert 0 into the Trie for prefix XORs

    vector<int> rmax(n + 1, 0);
    int R = 0;

    // Calculate maximum XOR for the right subarray
    for (int i = n - 1; i >= 0; i--) {
        R = R ^ a[i];
        if (i != n - 1) {
            rmax[i] = max(rmax[i + 1], query(R));
        } else {
            rmax[i] = query(R);
        }
        insert(R);
    }

    // Free the Trie and reset it for the left subarray
    delete trie;
    trie = new Node();
    insert(0);

    int ans = 0;
    int L = 0;

    // Calculate maximum XOR for the left subarray and combine with the right subarray
    for (int i = 0; i < n; i++) {
        L = L ^ a[i];
        ans = max(ans, rmax[i + 1] + query(L));
        insert(L);
    }

    cout << ans << endl;
    return 0;
}
