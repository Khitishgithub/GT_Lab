// wap to find the adjacent vertices of a hyper cube also count the total number of vertices and edges
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Hypercube {
    int dimension;
    int totalVertices;
    int totalEdges;
public:
    Hypercube(int n);
    void calculateVerticesAndEdges();
    void findAdjacentVertices(int vertex);
    int getTotalVertices() const { return totalVertices; }
    int getTotalEdges() const { return totalEdges; }
};

Hypercube::Hypercube(int n) : dimension(n), totalVertices(0), totalEdges(0) {}

void Hypercube::calculateVerticesAndEdges() {
    totalVertices = pow(2, dimension);
    totalEdges = dimension * totalVertices / 2;
}

void Hypercube::findAdjacentVertices(int vertex) {
    cout << "Adjacent vertices of vertex " << vertex << ":\n";
    for (int i = 0; i < dimension; ++i) {
        int adjVertex = vertex ^ (1 << i); // Toggle ith bit
        cout << adjVertex << endl;
    }
}

int main() {
    int dimension;
    cout << "Enter the dimension of the hypercube: ";
    cin >> dimension;

    Hypercube hypercube(dimension);
    hypercube.calculateVerticesAndEdges();

    cout << "Total number of vertices: " << hypercube.getTotalVertices() << endl;
    cout << "Total number of edges: " << hypercube.getTotalEdges() << endl;

    int vertex;
    cout << "Enter a vertex to find its adjacent vertices: ";
    cin >> vertex;

    hypercube.findAdjacentVertices(vertex);

    return 0;
}