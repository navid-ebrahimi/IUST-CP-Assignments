#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start_index = 0;
    int dp_table[n + 1];
    memset(dp_table, 0, sizeof(dp_table));
    for (int i = 2; i <= n; i++)
    {
        dp_table[i] = min(dp_table[i - 1] + abs(arr[i - 1]), dp_table[i - 2] + abs(arr[i - 2]));
    }
    cout << dp_table[n] << endl;

    return 0;
}