#include <iostream>
#include <set>

using namespace std;

set<string> S;

int main()
{
    int N;
    int cnt = 1;
    cin >> N;
    S.insert("ChongChong");
    string person1, person2;
    for (int i = 0; i < N; i++)
    {
        cin >> person1 >> person2;

        if (S.count(person1) && !S.count(person2))
        {
            S.insert(person2);
            cnt++;
        }
        else if (!S.count(person1) && S.count(person2))
        {
            S.insert(person1);
            cnt++;
        }
    }

    cout << cnt;
}