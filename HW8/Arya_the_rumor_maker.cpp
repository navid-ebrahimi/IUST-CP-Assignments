#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int V;
vector<bool> visited;

void DFS(int v, vector<vector<int>>& adj, stack<int>& stack) {
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); ++i) {
        int neighbor = adj[v][i];
        if (!visited[neighbor])
            DFS(neighbor, adj, stack);
    }
    stack.push(v);
}

void getT(vector<vector<int>>& adj, vector<vector<int>>& adjT) {
    for (int v = 0; v < V; v++) {
        for (int i = 0; i < adj[v].size(); ++i) {
            int neighbor = adj[v][i];
            adjT[neighbor].push_back(v);
        }
    }
}

int main() {
    int E; cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>());
    for (int i = 0; i < E; ++i) {
        int u, v; cin >> u >> v;
        v--; u--;
        adj[u].push_back(v);
    }
    stack<int> stack;
    for (int i = 0; i < V; i++)
    {
        visited.push_back(false);
    }
    
    for (int i = 0; i < V; i++) {
        if (visited[i] == false)
            DFS(i, adj, stack);
    }

    vector<vector<int>> adjT(V, vector<int>());
    getT(adj, adjT);

    for (int i = 0; i < V; i++)
        visited[i] = false;

    int count = 0;
    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (visited[v] == false) {
            DFS(v, adjT, stack);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
