#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 3;
vector<pair<int, int>> g[N];
int cost = 0;
vector<int> dist, parent;
vector<bool> vis;
const int INF = 1e9;

void primsMST(int source) {
    dist.resize(n, INF);
    parent.resize(n, -1);
    vis.resize(n, false);

    set<pair<int, int>> s;
    dist[source] = 0;
    s.insert({0, source});

    while (!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        
        int u = x.second;
        vis[u] = true;
        
        int v = parent[u];
        int w = x.first;
        cout << u << " " << v << " " << w << "\n";
        cost += w;
        
        for (auto it : g[u]) {
            if (vis[it.first])
                continue;
            if (dist[it.first] > it.second) {
                s.erase({dist[it.first], it.first});
                dist[it.first] = it.second;
                s.insert({dist[it.first], it.first});
                parent[it.first] = u;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primsMST(0);
    cout << "Total cost: " << cost << "\n"; 
    return 0;
}
