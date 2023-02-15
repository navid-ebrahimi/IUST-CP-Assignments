#include <iostream>
#include <string.h>


using namespace std;

int main()
{
    int question_number, score = 0;
    cin >> question_number;
    cin >> score;
    string answer;
    cin >> answer;
    for(int i = 0; i<question_number; i++)
    {
        if (answer[i] == 'o')
        {
            score++;
        }
        else if (answer[i] == 'x' && score != 0)
        {
            score--;
        }
    }
    cout << score << endl;
    return 0;
}