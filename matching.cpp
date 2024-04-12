// consider a subgraph from a given graph wap to check maching/maximum/maximal maching also determine maching number
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_V 100 

class Blossom {
private:
    int V;
    vector<int> graph[MAX_V];
    int match[MAX_V];
    int parent[MAX_V];
    int base[MAX_V];
    bool inQueue[MAX_V];
    queue<int> q;

    bool bfs(int start) {
        fill(parent, parent + V, -1);
        fill(inQueue, inQueue + V, false);
        while (!q.empty()) q.pop();

        q.push(start);
        inQueue[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (base[u] == base[v] || match[u] == v) continue;
                if (v == start || (match[v] != -1 && parent[match[v]] != -1)) {
                    int baseU = findBase(u), baseV = findBase(v);
                    if (baseU != baseV) {
                        vector<int> path = getPath(u, v, baseU, baseV);
                        processPath(u, v, baseU, baseV, path);
                        processPath(v, u, baseV, baseU, path);
                        return true;
                    }
                } else if (parent[v] == -1) {
                    parent[v] = u;
                    if (match[v] == -1) {
                        augmentPath(v);
                        return true;
                    }
                    q.push(match[v]);
                    inQueue[match[v]] = true;
                }
            }
        }
        return false;
    }

    void augmentPath(int end) {
        while (end != -1) {
            int next = match[parent[end]];
            match[end] = parent[end];
            match[parent[end]] = end;
            end = next;
        }
    }

    void processPath(int u, int v, int baseU, int baseV, vector<int>& path) {
        for (int i = 0; i < path.size(); ++i) {
            int w = path[i];
            if (base[w] != baseU) {
                base[w] = baseU;
                if (inQueue[w]) {
                    q.push(w);
                    inQueue[w] = true;
                }
            }
        }
    }

    vector<int> getPath(int u, int v, int baseU, int baseV) {
        vector<int> path;
        while (base[u] != baseU) {
            path.push_back(u);
            u = parent[match[u]];
        }
        path.push_back(u);
        reverse(path.begin(), path.end());
        while (base[v] != baseV) {
            path.push_back(v);
            v = parent[match[v]];
        }
        return path;
    }

    int findBase(int u) {
        while (u != base[u]) u = base[u];
        return u;
    }

public:
    Blossom(int vertices) {
        V = vertices;
        for (int i = 0; i < V; ++i)
            graph[i].clear();
        memset(match, -1, sizeof(match));
    }

    void addEdge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int maximumMatching() {
        for (int u = 0; u < V; ++u)
            if (match[u] == -1)
                for (int v : graph[u])
                    if (match[v] == -1) {
                        match[u] = v;
                        match[v] = u;
                        break;
                    }

        for (int u = 0; u < V; ++u)
            if (match[u] == -1 && bfs(u))
                memset(inQueue, false, sizeof(inQueue));
        int cnt = 0;
        for (int u = 0; u < V; ++u)
            if (match[u] != -1)
                ++cnt;
        return cnt / 2;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    cout << "Enter the number of edges in the graph: ";
    cin >> E;

    Blossom blossom(V);

    cout << "Enter the details of each edge (source destination):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        blossom.addEdge(u, v);
    }

    int matching = blossom.maximumMatching();
    cout << "The matching number is: " << matching << endl;

    return 0;
}