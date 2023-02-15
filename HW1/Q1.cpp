#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int curr_state = 0;
    int next_state = 0;
    int change = 0;
    cin >> curr_state;
    for(int i = 0; i<n-1;i++)
    {
        cin >> next_state;
        if (curr_state != next_state)
        {
            change++;
            curr_state = next_state;
        }
    }
    cout << change << endl;
    return 0;
}