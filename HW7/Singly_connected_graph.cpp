#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> adj[100000];
int visited[100000];
bool flag = false;
int start;

void dfs(int v) 
{
    visited[v] = 1;
    for (int i : adj[v]) 
    {
        if(visited[i] == 0 && !flag)
        {
            dfs(i);
        }
        else if (visited[i] == 2) 
        {
            flag = true;
            break;
        }
        
    }
    visited[v] = 2;
}

int main()
{
    ll v,e; cin >> v >> e;
    
    for (int i = 0; i < e; i++)
    {
        ll a,b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= v; i++)
    {
        fill(visited,visited+v+1,0);
        start = i;
        dfs(i);
        if (flag)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    
    return 0;
}