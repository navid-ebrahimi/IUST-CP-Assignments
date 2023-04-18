#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

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
        ll res = power(number, pow / 2);
        return ( res * res) % mod;
    }
    else
    {
        ll res = power(number, floor(pow/2));
        return (((number * res) % mod )* res) % mod;
    }
}

int main()
{
    ll n,k; cin >> n >> k;
    ll n_fact = factorial(n);
    ll k_fact = factorial(k);
    ll n_k_fact = factorial(n - k);
    cout << (((n_fact * power(k_fact, mod - 2)) % mod ) * power(n_k_fact, mod - 2)) % mod << endl;
    return 0;
}