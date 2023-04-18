#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ll n; cin >> n;
    ll min = 0;
    if (n%2 == 1)
    {
        for (ll i = 3; i < int(sqrt(n))+1; i++)
        {
            if (n % i == 0)
            {
                min = i;
                break;
            }
        }
        cout << n/min << ' ' << n - n/min << endl;
    }
    else
    {
        cout << n/2 << ' ' << n/2 << endl;
    }
    
    return 0;
}