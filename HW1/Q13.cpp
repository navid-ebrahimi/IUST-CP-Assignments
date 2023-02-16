#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

int main()
{
    string number; cin >> number;
    int size_of_number;

    size_of_number = number.size();
    if (number=="1")
        cout << "1" << endl;
    else if (number=="2")
        cout << "2" << endl;
    else
    {
        string result = "";
        if (number[size_of_number - 1] - '0' - 1 < 0)
        {
            int x = 1;
            while (number[size_of_number - x] - '0' - 1 < 0)
            {
                number[size_of_number - x] = '9';
                x++;
            }
            if (number[size_of_number - x] - '0' == 1 && size_of_number-x == 0)
            {
                number.erase(size_of_number-x, size_of_number-x+1);
            }
            else
            {
                number[size_of_number - x] = number[size_of_number - x] - '0' - 1 + '0';
            }
            cout << number << endl;
            return 0;
        }
        number[size_of_number - 1] = ((number[size_of_number-1] - '0')-1)+'0';
        for (int i = 0; i < size_of_number; i++)
        {
            result += number[i];
        }
        
        cout << result << endl;
    }
    
    return 0;
}