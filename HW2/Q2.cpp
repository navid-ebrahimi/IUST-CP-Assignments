#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <set>


using namespace std;


int main()
{
    int n; cin >> n;
    while(n--)
    {
        int size; cin >> size;
        string s; cin >> s;
        int arr1[size]; int arr2[size];
        set<char> a;
        string goal = "";
        int unique_number = 0;
        for(int i = 0; i<size; i++)
        {
            if (goal.find(s[i]) == string::npos)
            {
                goal += s[i];
                unique_number++;
            }
            arr1[i] = unique_number;
        }
        goal = "";
        unique_number = 0;
        for(int i = size; i>0; i--)
        {
            if (goal.find(s[i-1]) == string::npos)
            {
                goal += s[i-1];
                unique_number++;
            }
            arr2[i-1] = unique_number;
        }
        int max_num = arr2[0];
        for(int i = 0; i < size-1; i++)
        {
            max_num = max(max_num, arr1[i] + arr2[i+1]);
        }
        cout << max_num << endl;
    }
    return 0;
}
