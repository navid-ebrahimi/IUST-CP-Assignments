#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[550][550];
ll arr[550];
ll mod = 1e9+7;

ll factorial(ll number)
{
    ll result = 1;
    for (int i = 1; i <= number; i++)
    {
        result *= i;
        result %= mod;
    }
    return result;
}

ll power(ll number, ll pow)
{
    if (pow == 0)
    {
        return 1;
    }
    if (pow == 1)
    {
        return number;
    }
    if (pow % 2 == 0)
    {
        ll res = power(number, pow / 2) % mod;
        return ( res * res) % mod;
    }
    else
    {
        ll res = power(number, floor(pow/2)) % mod;
        return (((number * res) % mod )* res) % mod;
    }
}

ll compute(ll k, ll n)
{
    return (((factorial(n) * power(factorial(k), mod - 2))%mod) * power(factorial(n - k), mod - 2)) % mod;
}

int main()
{
    ll n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i+1; j < n; j+=2)
        {
            for(int k = i+1; k <= j; k+=2)
            {
                if(arr[i] > arr[k])
                {
                    ll Q = dp[i+1][k-1] % mod;
                    ll P = dp[k+1][j] % mod;
                    ll m = ((k-i-1)/2) % mod;
                    ll n = ((j-k)/2) % mod;
                    if (j-i == 1)
                    {
                        dp[i][j] = (dp[i][j]+1)%mod;
                        continue;
                    }
                    if(k-i == 1)
                    {
                        dp[i][j] += (((n+1)*P)%mod);
                        dp[i][j] %= mod;
                        continue;
                    }
                    if (k==j)
                    {
                        dp[i][j] = (dp[i][j]+dp[i+1][k-1])%mod;
                        continue;
                    }
                    
                    dp[i][j] += ((((P*Q)%mod)*(compute(m+1,n+m+1)))%mod);
                }
            }
        }
    }
    cout << dp[0][n-1] << '\n';

    return 0;
}