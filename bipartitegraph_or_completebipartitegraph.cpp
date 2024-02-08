#include <iostream>
#include <vector>

using namespace std;

bool isBipartite(vector<vector<int>>& graph, int v, vector<int>& color) {
    for (int u = 0; u < graph.size(); ++u) {
        if (graph[v][u]) {
            if (color[u] == -1) {
                color[u] = 1 - color[v];
                if (!isBipartite(graph, u, color)) {
                    return false;
                }
            } else if (color[u] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

bool isCompletelyBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), -1);

    for (int i = 0; i < graph.size(); ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!isBipartite(graph, i, color)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    if (isCompletelyBipartite(adjacencyMatrix)) {
        cout << "The graph is completely bipartite.\n";
    } else {
        cout << "The graph is not completely bipartite.\n";
    }

    return 0;
}
