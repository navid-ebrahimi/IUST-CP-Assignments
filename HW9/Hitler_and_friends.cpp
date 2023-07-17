#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef long long ll;

typedef pair<double, double> pi;

vector<vector<pi>> graph;

vector<double> dijkstra(ll start, ll n) {
    vector<double> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        ll u = pq.top().first;
        pq.pop();

        for (ll i = 0; i < graph[u].size(); i++) {
            double v = graph[u][i].first;
            double w = graph[u][i].second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }

    return dist;
}

int main() {
    ll n;
    cin >> n;

    string s; cin >> s;
    graph.resize(10+n);
    ll start = 0;
    for (ll i = 0; i < s.length(); i++) {
        if (i+1 < s.length())
        {
            graph[i].push_back(make_pair(i+1, 1));
        }
        if(i-1 >= 0)
        {
            graph[i].push_back(make_pair(i-1, 1));
        }
        graph[i].push_back(make_pair(s[i]-'0'+n, 0.5));
        graph[s[i]-'0'+n].push_back(make_pair(i, 0.5));
    }

    vector<double> dist = dijkstra(start, n+10);
    cout << dist[n-1] << endl;

    return 0;
}