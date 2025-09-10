#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
     
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    if (start == end) return 0; 
   
    vector<bool> visited(V, false);
    queue<pair<int, int>> q; 
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (neighbor == end) {
                    return dist + 1;
                }
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }
 
    return -1;
}

int main() { 
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int start = 0;
    int end = 4;
    cout << "Output: " << shortestPath(V, edges, start, end) << endl;

 
    V = 3;
    edges = {{0, 1}, {1, 2}};
    start = 0;
    end = 2;
    cout << "Output: " << shortestPath(V, edges, start, end) << endl;
 
    V = 4;
    edges = {{0, 1}, {1, 2}};
    start = 2;
    end = 3;
    cout << "Output: " << shortestPath(V, edges, start, end) << endl;

    return 0;
}
