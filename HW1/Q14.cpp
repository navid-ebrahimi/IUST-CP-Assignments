#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

int main()
{
    long long n; cin >> n;
    int max_Secret_Agent;
    if (n != 0)
        cin >> max_Secret_Agent;
    int people = 100 - max_Secret_Agent;
    for (int i = 0; i < n-1; i++)
    {
        int m; cin >> m;
        people += 100 - m;
        if (m<max_Secret_Agent)
        {
            max_Secret_Agent = m;
        }
    }
    if (people > 100)
        cout << "0 ";
    else
        cout << 100 - people << " ";
    cout << max_Secret_Agent << endl;
    return 0;
}
