#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string colors[4];
int number = 0;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string temp;
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        flag = false;
        for (int j = 0; j < number; j++)
        {
            if (temp == colors[j])
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            colors[number++] = temp;
        }
    }

    sort(colors, colors + number);
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            cout << colors[i] << " " << colors[j] << "\n";
        }
    }
}