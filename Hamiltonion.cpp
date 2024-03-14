
#include <iostream>
using namespace std;

const int MAX_V = 10; 

bool isSafe(int v, bool graph[MAX_V][MAX_V], int path[], int pos, int V) {
   
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; ++i)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCycleUtil(bool graph[MAX_V][MAX_V], int path[], int pos, int V) {
   
    if (pos == V) {
       
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; ++v) {
        if (isSafe(v, graph, path, pos, V)) {
            path[pos] = v;

            
            if (hamiltonianCycleUtil(graph, path, pos + 1, V))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle(bool graph[MAX_V][MAX_V], int V) {
    int path[MAX_V];
    for (int i = 0; i < V; ++i)
        path[i] = -1;

    // Start from the first vertex (index 0)
    path[0] = 0;

    if (!hamiltonianCycleUtil(graph, path, 1, V)) {
        cout << "No Hamiltonian cycle exists in the graph." << endl;
        return false;
    }

    cout << "Hamiltonian cycle exists in the graph: ";
    for (int i = 0; i < V; ++i)
        cout << path[i] << " ";
    cout << path[0] << endl;

    return true;
}

int main() {
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    bool graph[MAX_V][MAX_V];
    cout << "Enter the adjacency matrix of the graph:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    hamiltonianCycle(graph, V);

    return 0;
}