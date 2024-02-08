#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

void getGraphDetails(int graph[MAX_SIZE][MAX_SIZE], int size) {
    int nodes = size;
    int edges = 0;
    int parallelEdges = 0;
    int isComplete = 1; // Assume it is complete until proven otherwise

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (graph[i][j] == 1) {
                edges++;

                // Check for parallel edges
                if (i != j && graph[j][i] == 1) {
                    parallelEdges = 1;
                }
            }

            // Check for a complete graph
            if (i != j && graph[i][j] == 0) {
                isComplete = 0;
            }
        }
    }

    cout << "Number of nodes: " << nodes << endl;
    cout << "Number of edges: " << edges / 2 << endl; // Divide by 2 as the graph is undirected
    cout << "Graph is " << (isComplete ? "" : "not ") << "complete." << endl;
    cout << "Graph " << (parallelEdges ? "has" : "does not have") << " parallel edges." << endl;
}

int main() {
    int size;

    cout << "Enter the size of the graph (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Size exceeds the maximum limit." << endl;
        return 1;
    }

    int graph[MAX_SIZE][MAX_SIZE];

    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> graph[i][j];
        }
    }

    getGraphDetails(graph, size);

    return 0;
}
