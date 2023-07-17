#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> parents(100000, -1);
vector<int> parent1(10001, -1);
vector<int> parent2(10001, -1);

void getGrand1(int v)
{
    if(parents[v] == -1)
        return;
    parent1.push_back(parents[v]);
    return getGrand1(parents[v]);
}

void getGrand2(int v)
{
    if(parents[v] == -1)
        return;
    parent2.push_back(parents[v]);
    return getGrand2(parents[v]);
}

int main()
{
    int q; cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int p; cin >> p;
        p--;
        parents[i] = p;
    }

    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        parent1.clear();
        parent2.clear();
        parent1.push_back(u);
        parent2.push_back(v);

        getGrand1(u);
        getGrand2(v);
        bool flag = false;
        int max_par = -1;
        for(int i = 0; i < parent1.size(); i++)
        {
            for(int j = 0; j < parent2.size(); j++)
            {
                if(parent1[i] == parent2[j])
                {
                    max_par = max(max_par, parent1[i]+1);
                    flag = true;
                }
            }
        }
        if (flag == false)
            cout << 1 << endl;
        else
            cout << max_par << endl;
    }

    return 0;
}