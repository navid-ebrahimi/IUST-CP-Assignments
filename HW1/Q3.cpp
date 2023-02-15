#include <iostream>
#include <string.h>


using namespace std;

int main()
{
    int channel_number, curr_channel, num;
    cin >> channel_number >> curr_channel >> num;
    string channel_list[channel_number];
    curr_channel--;
    for(int i = 0; i<channel_number; i++)
    {
        cin >> channel_list[i];
    }
    cout << channel_list[(curr_channel + num)%channel_number] << endl;
    return 0;
}