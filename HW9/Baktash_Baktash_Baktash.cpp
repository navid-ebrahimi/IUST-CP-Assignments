#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"


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


    void changeValue(int x)
    {
        parent[x] = x+1;
    }
};


int main()
{
    fast;
    ll n, q; cin >> n >> q;
    DisjointSet ds(n+10);
    DisjointSet ds2(n+10);
    int arr[n+10];
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    
    int max_val = 0;
    for (int i = 0; i < q; i++)
    {
        ll type, g1, g2; cin >> type >> g1 >> g2;
        if (type == 1)
        {
            ds.unionSets(g1, g2);
        }
        else if (type == 2)
        {
            for (int j = g1; j < g2;)
            {
                ds.unionSets(j, j+1);
                ds2.changeValue(j);
                j = ds2.find(j);
            }
        }
        else if (type == 3)
        {
            if (ds.find(g1) == ds.find(g2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    
    return 0;
}