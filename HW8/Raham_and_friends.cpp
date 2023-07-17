#include <bits/stdc++.h>
using namespace std;
#define fast_ext ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int n, m, s, t;

int bfs(int start, vector<vector<int>>& adj) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    vector<int> depth(adj.size(), 0);
    
    q.push(start);
    visited[start] = true;
    

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
            {
                depth[neighbor] = depth[node] + 1;
                if (neighbor == s)
                {
                    return depth[neighbor];
                }
                visited[neighbor] = true;
                q.push(neighbor);
            }
            
        }
    }
    return -1;
}

int main()
{
    fast_ext;
    int c; cin >> c;
    while (c--)
    {
        cin >> n >> m >> s >> t;
        s--; t--;
        vector<vector<int>> adj(100001);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
        }
        vector<bool> visited(n, false);
        cout << bfs(t, adj) << '\n';
    }
    return 0;
}