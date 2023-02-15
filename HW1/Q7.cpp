#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int l = 0;
    for (int i = 0; i< n;i++)
    {
        int m; cin >> m;
        l += m;
    }
    if (k <= l)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
