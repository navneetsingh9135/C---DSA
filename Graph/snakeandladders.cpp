#include <bits/stdc++.h>
using namespace std;

int main() {
    int ladders, snakes;
    cin >> ladders;
    map<int, int> lad;
    map<int, int> snak;

    // Input for ladders
    for (int i = 0; i < ladders; i++) {
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }

    // Input for snakes
    cin >> snakes;
    for (int i = 0; i < snakes; i++) {
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }

    int moves = 0;
    queue<int> q;
    q.push(1);
    vector<int> vis(101, 0);  // to keep track of visited cells
    vis[1] = true;
    bool found = false;

    while (!q.empty() && !found) {
        int sz = q.size();
        while (sz--) {
            int t = q.front();
            q.pop();

            // Try all possible moves from 1 to 6 (like rolling a dice)
            for (int die = 1; die <= 6; die++) {
                int next = t + die;
                
                if (next == 100) {
                    found = true;
                    break;
                }

                // Ladder jump
                if (next <= 100 && lad[next] && !vis[lad[next]]) {
                    vis[lad[next]] = true;
                    q.push(lad[next]);
                }
                // Snake slide
                else if (next <= 100 && snak[next] && !vis[snak[next]]) {
                    vis[snak[next]] = true;
                    q.push(snak[next]);
                }
                // Regular move
                else if (next <= 100 && !vis[next] && !snak[next] && !lad[next]) {
                    vis[next] = true;
                    q.push(next);
                }
            }
        }
        moves++;
    }

    if (found)
        cout << moves;
    else
        cout << -1;

    return 0;
}
