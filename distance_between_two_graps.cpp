// // // WAP to display distance between 2 vertices in a graph find its essentricity of a vertex find radius and diameter
// #include <iostream>
// #include <queue>
// #include <vector>
// #include <limits>

// #define MAX_NODES 10
// #define INF std::numeric_limits<int>::max()

// using namespace std;

// // Function to calculate shortest distances from a source vertex to all other vertices in the graph
// void bfs(vector<vector<int>>& graph, int source, vector<int>& distances) {
//     int num_nodes = graph.size();
//     vector<bool> visited(num_nodes, false);
//     queue<int> q;

//     visited[source] = true;
//     distances[source] = 0;
//     q.push(source);

//     while (!q.empty()) {
//         int current = q.front();
//         q.pop();

//         for (int i = 0; i < num_nodes; ++i) {
//             if (graph[current][i] && !visited[i]) {
//                 visited[i] = true;
//                 distances[i] = distances[current] + 1;
//                 q.push(i);
//             }
//         }
//     }
// }

// // Function to find the eccentricity of a vertex
// int find_eccentricity(vector<vector<int>>& graph, int vertex) {
//     int num_nodes = graph.size();
//     vector<int> distances(num_nodes, INF);

//     bfs(graph, vertex, distances);

//     int eccentricity = 0;
//     for (int d : distances) {
//         if (d != INF && d > eccentricity) {
//             eccentricity = d;
//         }
//     }
//     return eccentricity;
// }

// int main() {
//     int num_nodes;
//     cout << "Enter the number of nodes in the graph: ";
//     cin >> num_nodes;

//     vector<vector<int>> graph(num_nodes, vector<int>(num_nodes, 0));

//     cout << "Enter the adjacency matrix of the graph:\n";
//     for (int i = 0; i < num_nodes; ++i) {
//         for (int j = 0; j < num_nodes; ++j) {
//             cin >> graph[i][j];
//         }
//     }

//     cout << "Enter the source and destination vertices to find their distance: ";
//     int source, destination;
//     cin >> source >> destination;

//     if (source < 0 || source >= num_nodes || destination < 0 || destination >= num_nodes) {
//         cerr << "Invalid source or destination vertex.\n";
//         return 1;
//     }

//     vector<int> distances(num_nodes, INF);
//     bfs(graph, source, distances);

//     cout << "Distance between vertex " << source << " and vertex " << destination << ": ";
//     if (distances[destination] != INF) {
//         cout << distances[destination] << endl;
//     } else {
//         cout << "Not reachable.\n";
//     }

//     // Finding eccentricity for each vertex
//     cout << "Eccentricity for each vertex:\n";
//     int radius = INF;
//     int diameter = 0;
//     for (int i = 0; i < num_nodes; ++i) {
//         int ecc = find_eccentricity(graph, i);
//         cout << "Eccentricity of vertex " << i << ": " << ecc << endl;
//         if (ecc < radius) {
//             radius = ecc;
//         }
//         if (ecc > diameter) {
//             diameter = ecc;
//         }
//     }
//     cout << "Radius of the graph: " << radius << endl;
//     cout << "Diameter of the graph: " << diameter << endl;

//     return 0;
// }

#include <iostream>
#include <queue>
#include <vector>
#include <limits>

#define MAX_NODES 10
#define INF std::numeric_limits<int>::max()

using namespace std;

// Function to calculate shortest distances from a source vertex to all other vertices in the graph
void bfs(vector<vector<int>>& graph, int source, vector<int>& distances) {
    int num_nodes = graph.size();
    vector<bool> visited(num_nodes, false);
    queue<int> q;

    visited[source] = true;
    distances[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < num_nodes; ++i) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                distances[i] = distances[current] + 1;
                q.push(i);
            }
        }
    }
}

// Function to find the eccentricity of a vertex
int find_eccentricity(vector<vector<int>>& graph, int vertex) {
    int num_nodes = graph.size();
    vector<int> distances(num_nodes, INF);

    bfs(graph, vertex, distances);

    int eccentricity = 0;
    for (int d : distances) {
        if (d != INF && d > eccentricity) {
            eccentricity = d;
        }
    }
    return eccentricity;
}

int main() {
    int num_nodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> num_nodes;

    vector<vector<int>> graph(num_nodes, vector<int>(num_nodes, 0));

    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            cin >> graph[i][j];
        }
    }

    // Finding eccentricity for each vertex
    cout << "Eccentricity for each vertex:\n";
    int radius = INF;
    int diameter = 0;
    for (int i = 0; i < num_nodes; ++i) {
        int ecc = find_eccentricity(graph, i);
        cout << "Eccentricity of vertex " << i << ": " << ecc << endl;
        if (ecc < radius) {
            radius = ecc;
        }
        if (ecc > diameter) {
            diameter = ecc;
        }
    }
    cout << "Radius of the graph: " << radius << endl;
    cout << "Diameter of the graph: " << diameter << endl;

    return 0;
}
// 0 1 1 1 
// 1 0 1 0
// 1 1 0 1
// 1 0 1 0