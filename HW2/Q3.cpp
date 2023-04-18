#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
#include <map>
typedef long long ll;

using namespace std;

// step1: collect numbers
// step2: sort
// step3: assign numbers with map
// step4: change numbers to 0-n
// step5: compute
int main()
{
    int t; cin >> t;
    vector<vector<int>> matrix;
    vector<int> numbers;
    map<int, int> map;

    for(int i = 0; i < t; i++)
    {
        int size; cin >> size;
        matrix.push_back(vector<int>());
        for (int j = 0; j < size; j++)
        {
            int x; cin >> x;
            matrix[i].push_back(x);
            numbers.push_back(x);
        }
        
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++)
    {
        map[numbers[i]] = i;
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = map[matrix[i][j]];
        }
    }
    int split = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = matrix[i].size() - 1; j > 0 ; j--)
        {
            if (matrix[i][j] !=  matrix[i][j - 1] + 1)
            {
                split++;
            }
        }
        
    }
    cout << split << ' ' << split + t - 1 << endl;
}