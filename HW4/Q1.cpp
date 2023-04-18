#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    string s; cin >> s;
    int n = s.size();
    int arr1[n], arr2[n];
    if(isupper(s[n - 1]))
        arr1[n - 1] = 1;
    else
        arr1[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--)
    {
        if (isupper(s[i]))
            arr1[i] = arr1[i + 1] + 1;
        else
            arr1[i] = arr1[i + 1];
    }
    if (islower(s[0]))
        arr2[0] = 1;
    else
        arr2[0] = 0;
    for(int i = 1; i < n; i++)
    {
        if (islower(s[i]))
            arr2[i] = arr2[i - 1] + 1;
        else
            arr2[i] = arr2[i - 1];
    }
    int min_count = INT_MAX ;
    for(int i = 0; i < n; i++)
    {
        if (arr1[i] + arr2[i] < min_count)
            min_count = arr1[i] + arr2[i];
    }
    
    if(min_count == 0)
        cout << 0 << endl;
    else
        cout << min_count - 1 << endl;
    return 0;
}