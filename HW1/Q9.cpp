#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int size_of_group; cin >> size_of_group;
        if (size_of_group > 3 || size_of_group == 1)
        {
            cout << "*";
        }
        else if (size_of_group==2)
        {
            cout << "**";
        }
        else if (size_of_group==3)
        {
            cout << "***";
        }
        cout << endl;
    }
    
    return 0;
}
