#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
#include <vector>


using namespace std;


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int min; cin >> min;
        int div = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int num; cin >> num;
            while (num >= min * 2)
            {
                div++;
                if (num - 2 * min < min)
                {
                    num -= min;
                }
                else
                {
                    num -= (2 * min - 1);
                }
            }
            
        }
        cout << div << endl;
    }
    
    
    return 0;
}
