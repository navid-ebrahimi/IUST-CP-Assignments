#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum_value(ll arr[], int i_start, int i_end)
{
    ll sum = 0;
    for(int i = i_start; i <= i_end; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n, k; cin >> n >> k;
    ll arr[k];
    ll matrix[k][k];
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        matrix[i][i] = 0;
    }
    for (int t = 1; t < k; t++)
    {
        for (int i = 0; i + t < k; i++)
        {
            ll min_value = 10e18;
            for(int j = i; j < i + t; j++)
            {
                min_value = min(matrix[i][j] + matrix[j + 1][i + t], min_value);
            }
            matrix[i][i + t] = min_value + sum_value(arr, i, i + t);
        }
    }
    cout << matrix[0][k - 1] << endl;
    return 0;
}