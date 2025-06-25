#include <stdio.h>
#include <stdlib.h>

#define N 100002

int vis[N];
int* adj[N];
int adj_size[N];

void add_edge(int x, int y) {
    adj[x] = (int*) realloc(adj[x], (adj_size[x] + 1) * sizeof(int));
    adj[x][adj_size[x]++] = y;
    adj[y] = (int*) realloc(adj[y], (adj_size[y] + 1) * sizeof(int));
    adj[y][adj_size[y]++] = x;
}

int main() {
    for (int i = 0; i < N; i++) {      
        vis[i] = 0;
        adj[i] = NULL;
        adj_size[i] = 0;
    }

    int n, m;
    scanf("%d %d", &n, &m);
    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        add_edge(x, y);
    }

    int queue[N];
    int front = 0, rear = 0;

    queue[rear++] = 1;
    vis[1] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d\n", node);

        for (int i = 0; i < adj_size[node]; i++) {
            int neighbor = adj[node][i];
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                queue[rear++] = neighbor;
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(adj[i]);
    }

    return 0;
}
