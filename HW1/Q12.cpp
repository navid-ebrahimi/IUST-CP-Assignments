#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

int main()
{
    long long n; cin >> n;
    long long neg = 0;
    for (long long i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        if (number < 0)
            neg++;
    }
    cout << neg * (n-1) << endl;
    return 0;
}
