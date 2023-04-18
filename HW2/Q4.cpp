#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int size; cin >> size;
        int arr1[N] = {0};
        int arr2[N] = {0};
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            int m; cin >> m;
            arr1[i] = (m);
        }
        for (int i = 0; i < size; i++)
        {
            int m; cin >> m;
            arr2[i] = (m);
        }
        sort(arr1, arr1 + size);
        sort(arr2, arr2 + size);
        int p1 = 0, p2 = 0;
        while(p1 < size && p2 < size)
        {
            if (arr1[p1] == arr2[p2])
            {
                arr1[p1] = INT_MAX;
                arr2[p2] = INT_MAX;
                p1++;
                p2++;
            }
            else if (arr1[p1] > arr2[p2])
            {
                p2++;
            }
            else{
                p1++;
            }
        }
        p1 = 0;
        p2 = 0;
        for(int i = 0; i < size; i++)
        {
            int len_of_int1 = to_string(arr1[i]).length();
            int len_of_int2 = to_string(arr2[i]).length();
            if (len_of_int1 > 1 && arr1[i] != INT_MAX)
            {
                arr1[i] = len_of_int1;
                count++;
            }
            if (len_of_int2 > 1 && arr2[i] != INT_MAX)
            {
                arr2[i] = len_of_int2;
                count++;
            }
        }
        sort(arr1, arr1 + size);
        sort(arr2, arr2 + size);
        p1 = 0;
        p2 = 0;
        while(p1 < size && p2 < size)
        {
            if (arr1[p1] == arr2[p2])
            {
                arr1[p1] = INT_MAX;
                arr2[p2] = INT_MAX;
                p1++;
                p2++;
            }
            else if (arr1[p1] > arr2[p2])
            {
                p2++;
            }
            else{
                p1++;
            }
        }
        p1 = 0; p2 = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr1[i] != 1 && arr1[i] != INT_MAX)
            {
                count++;
            }
            if (arr2[i] != 1 && arr2[i] != INT_MAX)
            {
                count++;
            }
        }
        
        cout << count << endl;
    }
    return 0;
}