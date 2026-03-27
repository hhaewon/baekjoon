#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    map<string, int> m;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        if (temp.compare("ENTER") == 0)
        {
            m.clear();
            continue;
        }
        if (m[temp])
        {
            m[temp]++;
        }
        else
        {
            cnt++;
            m[temp] = 1;
        }
    }
    cout << cnt;
}