#include <iostream>

using namespace std;

const int MAX = 100;

void displayGraph(int result[MAX][MAX], int vertices) {
    cout << "Resulting Graph:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void unionGraph(int graph1[MAX][MAX], int graph2[MAX][MAX], int result[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            result[i][j] = graph1[i][j] || graph2[i][j];
        }
    }
}

void intersectGraph(int graph1[MAX][MAX], int graph2[MAX][MAX], int result[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            result[i][j] = graph1[i][j] && graph2[i][j]; 
        }
    }
}

int main() {
    int vertices;

    cout << "Enter the number of vertices in the graphs: ";
    cin >> vertices;

    int graph1[MAX][MAX], graph2[MAX][MAX], result[MAX][MAX];

    cout << "Enter adjacency matrix for the first graph:\n";
    for (int i = 0; i < vertices; ++i)
        for (int j = 0; j < vertices; ++j)
            cin >> graph1[i][j];

    cout << "Enter adjacency matrix for the second graph:\n";
    for (int i = 0; i < vertices; ++i)
        for (int j = 0; j < vertices; ++j)
            cin >> graph2[i][j];

    unionGraph(graph1, graph2, result, vertices);
    displayGraph(result, vertices);

    intersectGraph(graph1, graph2, result, vertices);
    displayGraph(result, vertices);

    return 0;
}