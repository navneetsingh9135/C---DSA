#include<bits/stdc++.h>
using namespace std;
int int_size = 32;

class node {
public:
    node* next[2];

    node() {
        for (int i = 0; i < 2; i++) {
            next[i] = NULL;
        }
    }
};

node* trie;

void insert(int num) {
    node* it = trie;
    for (int i = int_size - 1; i >= 0; i--) {
        int cur_bit = (num >> i) & 1;
        if (!it->next[cur_bit]) {
            it->next[cur_bit] = new node(); // Fixed typo: `curr_bit` to `cur_bit`
        }
        it = it->next[cur_bit];
    }
}

int query(int num) {
    node* it = trie;
    int ans = 0;
    for (int i = int_size - 1; i >= 0; i--) {
        int cur_bit = (num >> i) & 1;
        int opposite_bit = cur_bit ^ 1; // Fixed logical issue: `xor` to `^`
        if (it->next[opposite_bit]) {
            it = it->next[opposite_bit];
            ans |= (1 << i); // Set the i-th bit in the result
        } else {
            it = it->next[cur_bit];
        }
    }
    return ans; // Fixed typo: `anss` to `ans`
}

int main() {
    int n;
    cin >> n; // Input the size of the ar'ytu  ray
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Input the array elements
    }

    trie = new node();
    insert(0); // Insert 0 into the Trie for prefix XORs

    vector<int> rmax(n + 1, 0); // Array to store max XOR for right subarrays
    int R = 0;

    // Calculate the maximum XOR for the right subarrays
    for (int i = n - 1; i >= 0; i--) {
        R = R ^ a[i]; // Update the XOR for the right subarray
        if (i != n - 1) {
            rmax[i] = max(rmax[i + 1], query(R)); // Fixed issue: `rmax = max()` to `rmax[i] = max()`
        } else {
            rmax[i] = query(R);
        }
        insert(R); // Insert the current XOR into the Trie
    }

    free(trie); // Free the Trie
    trie = new node(); // Reinitialize the Trie
    insert(0);

    int ans = 0; // Store the maximum XOR
    int L = 0;

    // Calculate the maximum XOR for the left subarray and combine with the right subarray
    for (int i = 0; i < n; i++) {
        L = L ^ a[i]; // Update the XOR for the left subarray
        ans = max(ans, rmax[i + 1] + query(L));
        insert(L); // Insert the current XOR into the Trie
    }

    cout << ans << endl; // Output the result
    return 0;
}
