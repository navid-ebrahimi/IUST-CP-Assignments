#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll matrix[1000][1000];

int main()
{
    ll V, E; cin >> V >> E;
    for (ll i = 0; i < E; i++)
    {
        ll u, v; cin >> u >> v;
        u--; v--;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    for (ll i = 0; i < V; i++)
    {
        for (ll j = 0; j < V; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}