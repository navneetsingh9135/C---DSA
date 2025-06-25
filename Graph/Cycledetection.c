#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 1000

int adj[MAX_NODES][MAX_NODES];
int adjSize[MAX_NODES];
bool visited[MAX_NODES];

bool isCycle(int src, int parent, int n) {
    visited[src] = true;
    for (int i = 0; i < adjSize[src]; i++) {
        int neighbor = adj[src][i];
        if (neighbor != parent) {
            if (visited[neighbor]) {
                return true;
            }
            if (!visited[neighbor] && isCycle(neighbor, src, n)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Initialize adjacency list and visited array
    for (int i = 0; i < n; i++) {
        adjSize[i] = 0;
        visited[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    bool cycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && isCycle(i, -1, n)) {
            cycle = true;
            break;  // No need to continue once a cycle is found
        }
    }

    if (cycle) {
        printf("Cycle is present\n");
    } else {
        printf("Cycle is not present\n");
    }

    return 0;
}
