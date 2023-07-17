#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u, graph, visited);
        }
    }
}

bool countConnectedVertices(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[i].size() != 0) {
            dfs(i, graph, visited);
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[i].size() != 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    ll n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool is_connected = countConnectedVertices(graph);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (graph[i].size() % 2 == 1) {
            count++;
        }
    }

    if (is_connected && (count == 0 || count == 2)) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }

    return 0;
}