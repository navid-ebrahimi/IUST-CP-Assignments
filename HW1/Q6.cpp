#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int curr=1, next=2;
    for (int i = 0; i < min(2,n); i++)
    {
        cout << '+';
    }
    for(int i = 2; i < n; i++)
    {
        int temp = next;
        next += curr;
        curr = temp;
        if (curr >= n)
        {
            return 0;
        }
        for(int j = curr + 1; j< next; j++)
        {
            cout << '-';
            if (j >= n)
            {
                return 0;
            }
        }
        cout << '+';
    }
    return 0;
}
