#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;

int main()
{
    ll n; cin >> n;
    if (n==1)
    {
        cout << 1 << endl;
        return 0;
    }
    ll arr[n+1];
    memset(arr, 0, sizeof(arr)+1);
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = (arr[i-1] * i) % mod; 
    }
    ll leftArr[n+1];
    ll rightArr[n+1];
    memset(leftArr, 0, sizeof(leftArr)+1);
    memset(rightArr, 0, sizeof(rightArr)+1);
    leftArr[n] = n;
    rightArr[n] = arr[n-1]-1;
    ll sum = ((leftArr[n] * rightArr[n]) % mod + arr[n]) % mod;
    for (int i = n-1; i > 2; i--)
    {
        leftArr[i] = (leftArr[i+1] * i) % mod;
        rightArr[i] = arr[i-1]-1;
        sum += leftArr[i] * rightArr[i];
        sum %= mod;
    }
    cout << sum << endl;


    return 0;
}