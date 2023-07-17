#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
int max_val = 0;
int r = 0;
vector<int> ret;
vector<int> to[200'001];
vector<int> from[200'001];

void dfs(int now, int prev, int w)
{
    if (max_val < w)
    {
        max_val = w;
        ret.clear();
    }
    if (max_val == w)
        ret.push_back(now);
    for (int nxt : from[now])
    {
        if (nxt == prev)
            continue;
        dfs(nxt, now, w - 1);
    }
    for (int nxt : to[now])
    {
        if (nxt == prev)
            continue;
        r++;
        dfs(nxt, now, w + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    for (int n = 1; n < N; n++)
    {
        int s, t;
        cin >> s >> t;
        to[t].push_back(s);
        from[s].push_back(t);
    }

    dfs(1, 0, 0);
    sort(ret.begin(), ret.end());
    cout << r - max_val << endl;
    for (int c : ret)
        cout << c << " ";
    cout << endl;

    return 0;
}