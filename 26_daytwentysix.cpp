#include <iostream>
#include <vector>
using namespace std;

 
bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
             return true;
        }
    }
    return false;
}
 
bool containsCycle(int V, vector<vector<int>>& edges) {
  
    vector<vector<int>> adj(V);
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);
 
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
     
    int V1 = 5;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    cout << (containsCycle(V1, edges1) ? "true" : "false") << endl;
 
    int V2 = 3;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}};
    cout << (containsCycle(V2, edges2) ? "true" : "false") << endl;

    
    int V3 = 4;
    vector<vector<int>> edges3 = {{0, 1}, {1, 2}, {2, 0}};
    cout << (containsCycle(V3, edges3) ? "true" : "false") << endl;

    return 0;
}
