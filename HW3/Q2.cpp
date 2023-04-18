#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
typedef long long ll;
using namespace std;

int main()
{
    ll n; cin >> n;
    bool bool_arr[2 * n];
    memset(bool_arr, false, sizeof(bool_arr));
    for (ll i = 2; i <= n; i++)
    {
        if (bool_arr[i] == false)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                bool_arr[j] = true;
            }
        }
    }
    ll count = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (bool_arr[i] == false)
        {
            count++;
        }
    }
    cout << count << endl;
}