// WAP to find number of spanning tree in complete and multi graph

// 0 1 0
// 1 0 1
// 0 1 0

// 0 1 1
// 1 0 1
// 0 1 1

#include <iostream>
#include <vector>
#include <limits>

#define MAX_NODES 10
#define INF std::numeric_limits<int>::max()

using namespace std;

long long int get_spanning_tree_count_complete(int num_nodes) {
    long long int spanning_tree_count = 1;
    for (int i = 2; i < num_nodes; ++i) {
        spanning_tree_count *= num_nodes;
    }
    return spanning_tree_count;
}

long long int get_spanning_tree_count(int graph[MAX_NODES][MAX_NODES], int num_nodes) {
    int degree[MAX_NODES] = {0};
    int laplacian[MAX_NODES][MAX_NODES] = {0};

    // Compute degree matrix and Laplacian matrix
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            if (i != j) {
                degree[i] += graph[i][j];
                laplacian[i][j] = -graph[i][j];
            }
        }
        laplacian[i][i] = degree[i];
    }

    // Calculate number of spanning trees using Kirchhoff's theorem
    long long int determinant = 1;
    for (int i = 0; i < num_nodes - 1; ++i) {
        for (int j = i + 1; j < num_nodes; ++j) {
            int factor = laplacian[j][i] / laplacian[i][i];
            for (int k = 0; k < num_nodes; ++k) {
                laplacian[j][k] -= factor * laplacian[i][k];
            }
        }
        determinant *= laplacian[i][i];
    }

    return determinant;
}

int getNumEdges(int adjMatrix[][MAX_NODES], int n) {
    int numEdges = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            numEdges += adjMatrix[i][j];
        }
    }
    return numEdges;
}

bool isComplete(int adjMatrix[][MAX_NODES], int n) {
    int maxEdges = n * (n - 1) / 2;
    return getNumEdges(adjMatrix, n) == maxEdges;
}

int main() {
    int num_nodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> num_nodes;

    if (num_nodes <= 0 || num_nodes > MAX_NODES) {
        cerr << "Invalid number of nodes. Must be between 1 and " << MAX_NODES <<endl;
        return 1;
    }

    int graph[MAX_NODES][MAX_NODES];
    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            cin >> graph[i][j];
        }
    }

    bool isCompleteGraph = isComplete(graph, num_nodes);
    cout << "Is the graph complete? " << (isCompleteGraph ? "Yes" : "No") << endl;

    long long int spanning_tree_count;
    if (isCompleteGraph) {
        spanning_tree_count = get_spanning_tree_count_complete(num_nodes);
    } else {
        spanning_tree_count = get_spanning_tree_count(graph, num_nodes);
    }

    cout << "Number of spanning trees: " << spanning_tree_count << std::endl;

    return 0;
}