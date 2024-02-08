#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 10; 

bool areIsomorphic(vector<vector<int>>& graph1, vector<vector<int>>& graph2, vector<int>& permutation) {
    int size = graph1.size();

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if ((graph1[i][j] != 0 && graph2[permutation[i]][permutation[j]] == 0) ||
                (graph1[i][j] == 0 && graph2[permutation[i]][permutation[j]] != 0)) {
                return false;
            }
        }
    }

    return true;
}

bool checkIsomorphism(vector<vector<int>>& graph1, vector<vector<int>>& graph2) {
    int size = graph1.size();

    // Generate all possible permutations of vertices
    vector<int> permutation(size);
    for (int i = 0; i < size; ++i) {
        permutation[i] = i;
    }

    do {
        
        if (areIsomorphic(graph1, graph2, permutation)) {
            return true;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    return false;
}

int main() {
    int size;

    cout << "Enter the size of the graphs (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Size exceeds the maximum limit." << endl;
        return 1;
    }

   
    vector<vector<int>> graph1(size, vector<int>(size, 0));
    vector<vector<int>> graph2(size, vector<int>(size, 0));

    cout << "Enter the adjacency matrix for the first graph:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> graph1[i][j];
        }
    }

    cout << "Enter the adjacency matrix for the second graph:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> graph2[i][j];
        }
    }

    // Check if the graphs are isomorphic
    if (checkIsomorphism(graph1, graph2)) {
        cout << "The graphs are isomorphic." << endl;
    } else {
        cout << "The graphs are not isomorphic." << endl;
    }

    return 0;
}
