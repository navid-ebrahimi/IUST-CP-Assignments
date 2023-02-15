#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int n = s.size();
    int ball_num = 0;
    int i = 1;
    while(i != n)
    {
        if (((s[i]-'0') == 1 && (s[i+1]-'0') == 0) || ((s[i]-'0') == 0 && (s[i+1]-'0') == 1))
        {
            ball_num+=2;
            s.erase(i, 2);
        }
        else if (((s[i]-'0') == 0 && (s[i-1]-'0') == 1) || ((s[i]-'0') == 1 && (s[i-1]-'0') == 0))
        {
            ball_num+=2;
            s.erase(i-1, 2);
            i--;
        }
        else
            i++;
    }
    cout << ball_num << endl;
    return 0;
}
