#include <iostream>
#include <climits>

#define V 6 
using namespace std;

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    cout << " -> " << j;
}

void printSolution(int dist[], int n, int parent[], int destination) {
    cout << "Shortest Path from source to destination: " << dist[destination] << endl;
    cout << "Path: ";
    printPath(parent, destination);
    cout << endl;
}

void dijkstra(int graph[V][V], int src, int destination) {
    int dist[V];    
    bool sptSet[V];
    int parent[V];  

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }

    printSolution(dist, V, parent, destination);
}

int main() {
    int graph[V][V] = {{0, 1, 4, 0, 0, 0},
                       {0, 0, 2, 7, 0, 0},
                       {0, 0, 0, 0, 3, 0},
                       {0, 0, 0, 0, 0, 2},
                       {0, 0, 0, 0, 0, 5},
                       {0, 0, 0, 0, 0, 0}};

    int source = 0;
    int destination = 5;

    dijkstra(graph, source, destination);

    return 0;
}