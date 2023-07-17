#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll max_value = INT32_MAX;
ll sum = 0;
ll from = 0;
ll to = 0;

struct Edge {
    ll from, to, weight;
};

bool cmp(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

ll find(ll x, vector<ll>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void unite(ll x, ll y, vector<ll>& parent, vector<ll>& rank) {
    ll px = find(x, parent), py = find(y, parent);
    if (rank[px] < rank[py]) {
        parent[px] = py;
    } else {
        parent[py] = px;
        if (rank[px] == rank[py]) {
            rank[px]++;
        }
    }
}

vector<Edge> kruskal(ll n, vector<Edge>& edges) {
    vector<Edge> result;
    vector<ll> parent(n+1), rank(n+1);
    for (ll i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    sort(edges.begin(), edges.end(), cmp);
    for (auto edge : edges) {
        if (edge.from == from && edge.to == to)
        {
            continue;
        }
        ll root1 = find(edge.from, parent);
        ll root2 = find(edge.to, parent);
        if (root1 != root2) {
            result.push_back(edge);
            sum += edge.weight;
            unite(root1, root2, parent, rank);
        }
    }
    if (result.size() == n-1)
        max_value = min(max_value, sum);
    sum = 0;
    return result;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (ll i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }
    vector<Edge> mst = kruskal(n, edges);
    max_value = INT32_MAX;
    for (ll i = 0; i < mst.size(); i++)
    {
        from = mst[i].from;
        to = mst[i].to;
        vector<Edge> mst2 = kruskal(n, edges);
    }

    if (max_value != INT32_MAX)
        cout << max_value << endl;
    else
        cout << -1 << endl;
    return 0;
}
