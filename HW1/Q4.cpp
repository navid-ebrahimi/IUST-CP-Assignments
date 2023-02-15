#include <iostream>
using namespace std;

int one_bit_number = 0;

int main()
{
	int n;
    cin >> n;
    int binaryNum[32];
    int binaryLoc[32];
	int i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
        if (binaryNum[i] == 1)
        {
            one_bit_number++;
            binaryLoc[one_bit_number] = i;
        }
		n = n / 2;
		i++;
	}
    cout << one_bit_number << endl;
    for (int j = 1; j <= one_bit_number; j++)
    {
        cout << binaryLoc[j] << " ";
    }
	return 0;
}
