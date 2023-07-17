#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
const ll mod=1e9+7;
const int N=1e5+5;

int n,m,k,t,a[N],d1[N],d2[N],dist[N],cnt[N];
vector<int> adj[N];
bool mark[N];

ll pow(ll number, ll poww)
{
    if (poww == 0)
    {
        return 1;
    }
    if (poww == 1)
    {
        return number;
    }
    if (poww % 2 == 0)
    {
        ll res = pow(number, poww / 2);
        return ( res * res) % mod;
    }
    else
    {
        ll res = pow(number, floor(poww/2));
        return (((number * res) % mod )* res) % mod;
    }
}
ll inv(ll x)
{
    return pow(x, mod - 2);
}

void BFS1(int v){
    fill(mark,mark+n+1,0);
    queue<int> Q;
    Q.push(v);
    d1[v]=0;
    mark[v]=1;
    while(!Q.empty()){
        int v=Q.front();
        Q.pop();
        for(int u: adj[v])
            if(!mark[u]){
                Q.push(u);
                d1[u]=d1[v]+1;
                mark[u]=1;
            }
    }
}

void BFS2(int v){
    fill(mark,mark+n+1,0);
    queue<int> Q;
    Q.push(v);
    d2[v]=0;
    mark[v]=1;
    while(!Q.empty()){
        int v=Q.front();
        Q.pop();
        for(int u: adj[v])
            if(!mark[u]){
                Q.push(u);
                d2[u]=d2[v]+1;
                mark[u]=1;
            }
    }
}

int main()
{
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS1(1);
    int mx=*max_element(d1,d1+n+1);
    for(int i=1;i<=n;i++)
        if(d1[i]==mx){
            k=i;
            break;
        }
    BFS1(k);
    mx=*max_element(d1,d1+n+1);
    for(int i=1;i<=n;i++)
        if(d1[i]==mx){
            k=i;
            break;
        }
    BFS2(k);
    for(int i=1;i<=n;i++)
        dist[i]=max(d1[i],d2[i]);
    for(int i=1;i<=n;i++)
        cnt[dist[i]]++;
    int sum=1;
    for(int i=1;i<=n;i++){
        cout << min(sum,n) << ' ';
        sum+=cnt[i];
    }
    cout << endl;
    return 0;
}