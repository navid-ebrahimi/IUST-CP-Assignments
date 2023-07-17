#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll arr[18];
ll rules[18][18];

ll compute_function(bitset<18> num1, int j)
{
    ll val = arr[j];
    ll max_value = 0;
    for (int i = 0; i < n; i++)
    {
        if (num1[i] == 1 && rules[i][j] > max_value)
        {
            max_value = rules[i][j];
        }
    }
    val += max_value;
    return val;
}

int main()
{
    ll m, k; cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < k; i++)
    {
        ll x, y; cin >> x >> y;
        cin >> rules[x-1][y-1];
    }
    ll dp[(int)pow(2,n)];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < (int)pow(2,n); i++)
    {
        bitset<18> num1(i);
        for (int j = 0; j < n; j++)
        {
            if (num1[j] == 1)
            {
                ll res = compute_function(num1, j);
                if (dp[i] < dp[(int)(i - pow(2,j))]+res)
                    dp[i] = dp[(int)(i - pow(2,j))]+res;
            }
        }
    }
    ll max_val = 0;
    for (int i = 0; i < (int)pow(2,n); i++)
    {
        bitset<19> num1(i);
        if (num1.count() == m && max_val < dp[i])
        {
            max_val = dp[i];
        }
    }
    cout << max_val << endl;
    return 0;
}