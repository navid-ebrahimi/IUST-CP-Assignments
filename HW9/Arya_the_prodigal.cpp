#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, t, k;
int countt = 0;

class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Node {
public:
    int name;
    int distance;

    Node(int _name, int _distance) : name(_name), distance(_distance) {}
};

void bfs(vector<vector<pair<int, int>>>& graph, int start, DisjointSet& ds) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);

    queue<Node> q;
    q.push(Node(start, 0));
    visited[start] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        cout << "Node: " << current.name << ", Distance: " << current.distance << endl;

        for (const pair<int, int>& edge : graph[current.name]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (!visited[neighbor]) {
                q.push(Node(neighbor, current.distance + weight));
                if (current.distance + weight >= k) {
                    if (ds.find(current.name) != ds.find(neighbor))
                        countt++;
                }
                else
                {
                    ds.unionSets(current.name, neighbor);
                }
                visited[neighbor] = true;
            }
        }
    }
}


int main()
{
    cin >> n >> m >> t >> k;
    vector<vector<pair<int, int>>> graph(n+1);
    DisjointSet ds(n+10);
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    for (int i = 0; i < t; i++)
    {
        int start; cin >> start;
        bfs(graph, start, ds);
        cout << countt << endl;
        countt = 0;
    }
    




    return 0;
}