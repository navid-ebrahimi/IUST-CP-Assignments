#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

int n, k;
vector<vector<int>> dp;
vector<vector<int>> g;
int ans;

void dfs(int v, int pr = -1, int dist = 0){
    dp[v][0] = 1;
    for(auto i : g[v]){
        if(i != pr){
            dfs(i, v, dist + 1);
            for(int j = 1;j <= k;j++){
                dp[v][j] += dp[i][j - 1];
            }
        }
    }
    ans += dp[v][k];
    int na = 0;
    for(int i : g[v]){
        if(i == pr)
            continue;
        for(int j = 1;j <= k - 1;j++){
            na += dp[i][j - 1] * (dp[v][k - j] - dp[i][k - j - 1]);
        }
    }
    ans += na / 2;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    g.resize(n + 1);
    dp.resize(n + 1);
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        dp[i].resize(k + 1);
    }
    dp[n].resize(k + 1);
    ans = 0;
    dfs(1);
    cout << ans;
    return 0;
}