#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int>>& adj_list, int root, vector<int>& dist, vector<int>& parent) {
    int n = adj_list.size();
    dist.assign(n, -1);
    parent.assign(n, -1);
    dist[root] = 0;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj_list[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int graph_diameter(vector<vector<int>>& adj_list) {
    int n = adj_list.size();
    int root = 0;

    vector<int> dist(n), parent(n);
    bfs(adj_list, root, dist, parent);
    int farthest = max_element(dist.begin(), dist.end()) - dist.begin();

    bfs(adj_list, farthest, dist, parent);
    int diameter = *max_element(dist.begin(), dist.end());
    return diameter;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int diameter = graph_diameter(adj_list);
    cout << diameter << endl;
    return 0;
}
