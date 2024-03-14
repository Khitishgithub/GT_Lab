#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) : vertices(V), adjMatrix(V, vector<int>(V, 0)) {}

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    bool isEulerian() {
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                if (adjMatrix[i][j] == 1 && (degree(i) % 2 != 0 || degree(j) % 2 != 0))
                    return false;

        return true;
    }

    void printEulerianCycle() {
        if (!isEulerian()) {
            cout << "The graph is not Eulerian. Cannot find Eulerian cycle." << endl;
            return;
        }

        vector<int> circuit;
        stack<int> st;
        st.push(0);

        while (!st.empty()) {
            int u = st.top();
            int v;

            for (v = 0; v < vertices; v++) {
                if (adjMatrix[u][v] == 1) {
                    st.push(v);
                    adjMatrix[u][v] = 0;
                    adjMatrix[v][u] = 0;
                    break;
                }
            }

            if (v == vertices) {
                st.pop();
                circuit.push_back(u);
            }
        }

        cout << "Eulerian Cycle: ";
        for (int i = circuit.size() - 1; i >= 0; i--)
            cout << circuit[i] << " ";
        cout << endl;
    }

private:
    int degree(int v) {
        int deg = 0;
        for (int i = 0; i < vertices; i++)
            deg += adjMatrix[v][i];
        return deg;
    }
};

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    if (graph.isEulerian()) {
        cout << "The graph is Eulerian." << endl;
        graph.printEulerianCycle();
    } else {
        cout << "The graph is not Eulerian." << endl;
    }

    return 0;
}