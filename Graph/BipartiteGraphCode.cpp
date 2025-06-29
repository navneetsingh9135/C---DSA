#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipart;

void color(int u, int curr) {
    if (col[u] != -1 && col[u] != curr) {
        bipart = false;
        return;
    }
    col[u] = curr;
    if (vis[u]) return;
    vis[u] = true;

    for (auto i : adj[u]) {
        color(i, curr ^ 1);  // Flip color using XOR
    }
}

int main() {
    bipart = true;
    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);  // Initialize color vector with -1 (uncolored)

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            color(i, 0);  // Start coloring with color 0
        }
    }

    if (bipart)
        cout << "Graph is bipartite";
    else
        cout << "Graph is not bipartite";

    return 0;
}
