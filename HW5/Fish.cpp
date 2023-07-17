#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
double arr[18][18];

double compute_fuction(bitset<18> num1, int j)
{
    double val = 0;
    for (int i = 0; i < n; i++)
    {
        if (num1[i] == 1)
        {
            val += arr[i][j];
        }
    }
    val = val / ((num1.count()+1)*(num1.count())/2);
    return val;
}

int main()
{
    n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    double dp[(int)pow(2,n) + 1];
    memset(dp, 0, sizeof(dp));
    dp[(int)pow(2,n)] = 1;
    dp[(int)pow(2,n)-1] = 1;
    for (int i = pow(2,n) - 2; i > 0; i--)
    {
        bitset<18> num1(i);
        for (int j = 0; j < n; j++) 
        {
            if (num1[j] == 0)
            {
                double res = compute_fuction(num1, j);
                dp[i] += dp[(int)(i + pow(2,j))] * res;
            }
        }
    }    
    for (int i = 0; i < pow(2,n); i++)
    {
        if (pow(2,i) < pow(2,n))
            cout << fixed << setprecision(6) << dp[(int)pow(2,i)] << " ";
        else break;
    }
    cout << endl;
    return 0;
}