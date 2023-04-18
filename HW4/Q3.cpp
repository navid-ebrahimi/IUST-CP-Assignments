#include <bits/stdc++.h>
#define int long long
using namespace std;

// binary search that returns the index of the first element that is greater than or equal to the target
int search(int arr[], int n, int target)
{
    int l = 0, r = n - 1;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int32_t main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int target[2*n];
    memset(target, 0, sizeof(target));
    int size = 1;
    target[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        if (arr[i] > target[size - 1])
        {
            target[size] = arr[i];
            size++;
        }
        else
        {
            // use search function
            int index = search(target, size, arr[i]);
            if (target[index] > arr[i])
                target[index] = arr[i];
        }
    }
    cout << size << endl;
    return 0;
}