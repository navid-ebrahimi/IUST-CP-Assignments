#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, q; cin >> n >> q;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] += dp[i - 1] + arr[i];
    }
    
    while (q--)
    {
        int l, r; cin >> l >> r;
        l-=2; r--;
        if (l < 0)
            cout << dp[r] << endl;
        else
            cout << dp[r] - dp[l] << endl;
    }
    
    return 0;
}