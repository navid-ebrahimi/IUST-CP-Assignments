#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string father, mother, child; cin >> father >> mother >> child;
        if (child[0] == 'O' && child[1] == '-')
        {
            cout << "valid" << endl;
        }
        else
        {
            map<char, bool> my_map = {
            { 'A', false },
            { '+', false },
            { 'B', false },
            { 'O', true}
            };
            int flag = 0;
            long long father_size = father.size(); long long mother_size = mother.size();
            for(long long j = 0; j < max(father_size, mother_size); j++)
            {
                if (j<father_size)
                {
                    my_map[father[j]] = true;
                }
                if (j<mother_size)
                {
                    my_map[mother[j]] = true;
                }
            }
            for(int i = 0; i<child.size(); i++)
            {
                if (!my_map[child[i]] && child[i] != '-')
                {
                    cout << "invalid" << endl;
                    flag++;
                    break;
                }
            }
            if (flag == 0)
                cout << "valid" << endl;
        }
    }
    

    return 0;
}
