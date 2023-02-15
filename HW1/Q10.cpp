#include <bits/stdc++.h>
using namespace std;

string A, B;
void print(int A_size, int B_size, int x_loc, int y_loc)
{
    for (int i = 0; i<B_size; i++)
    {
        for (int j = 0; j<A_size; j++)
        {
            if (i == y_loc)
            {
                cout << A[j];
            }
            else if (j == x_loc)
            {
                cout << B[i];
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}


int main()
{
    cin >> A >> B;
    int A_size = A.size(); int B_size = B.size();
    for (int i = 0; i<A_size; i++)
    {
        for (int j = 0; j<B_size; j++)
        {
            if (A[i] == B[j])
            {
                print(A_size, B_size, i, j);
                return 0;
            }
        }
    }
    return 0;
}
