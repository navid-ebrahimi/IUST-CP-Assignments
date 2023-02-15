#include <iostream>
using namespace std;

int main()
{
    int num; cin >> num;
    num++;
    for (int i = num; i < 8000; i++)
    {
        int temp = num;
        int sign = 0;
        bool numbers[10] = {false, false, false, false, false, false, false, false, false, false};
        for(int j = 0; j < 4; j++)
        {
            if (!numbers[temp % 10])
                numbers[temp % 10] = true;
            else
            {
                sign = 1;
                break;
            }
            temp /= 10;
        }
        if (sign != 1)
        {
            cout << i << endl;
            break;
        }
        num++;
    }
    return 0;
}
