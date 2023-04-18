#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long ll;

int find_bit_one(ll n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            count++;
        }
        n /= 2;
    }
    return count;
}

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int goals[2];
    cin >> goals[0] >> goals[1];
    sort(goals, goals + 2);
    int count = 0;
    int c = 0;
    for (int i = goals[0] + 1; i <= goals[1]; i++)
    {
        if (s[i - 1] == 'H')
        {
            count++;
        }
        if (s[i - 1] == 'P')
        {
            c+=find_bit_one(count);
            count = 0;
        }
    }
    cout << c << endl;
    return 0;
}