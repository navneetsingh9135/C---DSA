#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    
    for (int i = 0; i < m; i++) { // m edges are given as input
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            pq.push(i);
        }
    }

    int cnt = 0; // Initialize cnt to 0
    while (!pq.empty()) {
        cnt++;
        int x = pq.front();
        pq.pop();
        cout << x << " ";
        
        for (auto it : adj[x]) {
            indeg[it]--;
            if (indeg[it] == 0) {
                pq.push(it);
            }
        }
    }
    
    return 0;
}
