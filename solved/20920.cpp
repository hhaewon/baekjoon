#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
map<string, int> wordCnt;
vector<string> words;

string temp;
bool cmp(const string &a, const string &b)
{
    if (wordCnt[a] == wordCnt[b] && a.length() == b.length())
    {
        return a < b;
    }
    if (wordCnt[a] == wordCnt[b])
    {
        return a.length() > b.length();
    }
    return wordCnt[a] > wordCnt[b];
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;

        if (temp.length() < M)
        {
            continue;
        }
        if (wordCnt[temp] == 0)
        {
            words.push_back(temp);
        }
        wordCnt[temp]++;
    }

    sort(words.begin(), words.end(), cmp);

    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << "\n";
    }
}