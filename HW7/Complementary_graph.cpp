#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ll V, E; cin >> V >> E;
    map<string, int> my_dict;
    for (ll i = 0; i < E; i++)
    {
        ll u, v; cin >> u >> v;
        string str = to_string(u) + " " + to_string(v);
        my_dict.insert({str, 1});
    }
    ll c; cin >> c;
    for (ll i = 0; i < c; i++)
    {
        ll u, v; cin >> u >> v;
        string str = to_string(u) + " " + to_string(v);
        string str2 = to_string(v) + " " + to_string(u);
        if (my_dict.find(str) != my_dict.end() || my_dict.find(str2) != my_dict.end()) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}