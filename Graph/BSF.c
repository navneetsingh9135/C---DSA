#include <stdio.h>
#include <stdbool.h>

#define N 100002

bool vis[N];
int adj[N][N];
int adjSize[N];

int queue[N];
int front = 0, back = 0;

void enqueue(int value) {
    queue[back++] = value;
}

int dequeue() {
    return queue[front++];
}

bool isQueueEmpty() {
    return front == back;
}

int main() {
    // Initialize visited array and adjacency list
    for (int i = 0; i < N; i++) {
        vis[i] = false;
        adjSize[i] = 0;
    }

    int n, m;
    scanf("%d %d", &n, &m);
    
    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        adj[x][adjSize[x]++] = y;
        adj[y][adjSize[y]++] = x;
    }

    enqueue(1);
    vis[1] = true;

    while (!isQueueEmpty()) {
        int node = dequeue();
        printf("%d\n", node);

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                enqueue(neighbor);
            }
        }
    }

    return 0;
}
