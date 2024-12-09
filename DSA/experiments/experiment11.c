#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10

void dijkstra(int graph[MAX_NODES][MAX_NODES], int source, int num_nodes) {
    int dist[MAX_NODES]; // Array to store shortest distances from source
    int visited[MAX_NODES]; // Array to mark visited nodes

    // Initialize all distances as INFINITE and mark all nodes as not visited
    for (int i = 0; i < num_nodes; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance of source node from itself is 0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < num_nodes - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = -1;
        int min_distance = INT_MAX;
        for (int v = 0; v < num_nodes; v++) {
            if (visited[v] == 0 && dist[v] <= min_distance) {
                min_distance = dist[v];
                u = v;
            }
        }

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < num_nodes; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %d\n", i, dist[i]);
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 7, 9, 0, 0, 0},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 0},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {0, 0, 0, 0, 9, 0}
    };
    int source = 0;
    int num_nodes = 6;

    dijkstra(graph, source, num_nodes);

    return 0;
}