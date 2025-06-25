#include<stdio.h>
#define MAX 10

void breadth_first_search(int adj[][MAX], int visited[], int start) {
    int queue[MAX], front = -1, rear = -1, i;

    // Enqueue the start node
    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal:\n");

    while (front != rear) {
        // Dequeue the front element
        start = queue[++front];
        printf("%d ", start);

        // Check all adjacent nodes
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;  // Enqueue the adjacent node
                visited[i] = 1;     // Mark as visited
            }
        }
    }
}

int main() {
    int visited[MAX] = {0};       // To keep track of visited nodes
    int adj[MAX][MAX];            // Adjacency matrix
    int i, j, nodes;

    // Input the number of nodes in the graph
    printf("Enter the number of nodes (<= %d): ", MAX);
    scanf("%d", &nodes);

    if (nodes > MAX || nodes <= 0) {
        printf("Invalid number of nodes. Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix (%d x %d):\n", nodes, nodes);
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Perform BFS starting from node 0
    breadth_first_search(adj, visited, 0);

    return 0;
}
