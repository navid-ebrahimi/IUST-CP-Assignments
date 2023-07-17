#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100000];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll Q; cin >> Q;
    while (Q--)
    {
        ll s, k; cin >> s >> k;
        s--;
        ll sum = 0;
        for (int i = s; i < n; i+=k)
        {
            sum += arr[i];
        }
            cout << sum << '\n';
    }
    
    return 0;
}