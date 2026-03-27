#include <iostream>

using namespace std;

string encode(string plain, string key)
{
    int sum[200000];
    string result;

    result.reserve(plain.size());
    for (int i = 0; i < plain.size(); i++)
    {
        sum[i] = (plain[i] - 'A' + 1 + key[i % key.size()] - 'A' + 1);
        if (sum[i] > 26)
        {
            sum[i] -= 26;
        }
        result.push_back(sum[i] + 'A' - 1);
    }

    return result;
}

int diff[200000];

int main()
{
    string correctkey;
    string plain;
    // for (int i = 0; i < 200000; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         plain.push_back('A');
    //     }
    //     else
    //     {
    //         plain.push_back('Z');
    //     }
    // }
    // string encoded = encode(plain, correctkey);
    string encoded;
    string keyPredictd;

    cin >> plain;
    cin >> encoded;
    int size = plain.size();
    for (int i = 0; i < size; i++)
    {
        diff[i] = (encoded[i] - plain[i] + 26) % 26;
        if (diff[i] == 0)
        {
            diff[i] = 26;
        }
        // cout << diff[i] << "\n";
    }

    int i = 0;
    int j = 1;
    int overlapping = 0;
    int keySize = 0;
    while (j < size)
    {
        if (diff[i] != diff[j])
        {
            if (overlapping)
            {
                i = 0;
                overlapping = 0;
            }
            else
            {
                j++;
            }
        }
        else
        {
            if (!overlapping)
            {
                keySize = j;
                overlapping = 1;
            }
            i++;
            j++;
        }
    }

    if (keySize == 0)
    {
        keySize = size;
    }

    for (int k = 0; k < keySize; k++)
    {
        keyPredictd.push_back(diff[k] + 'A' - 1);
    }

    cout << keyPredictd;
    // cout << "correctKey : " << correctkey << ", predicted Key : " << keyPredictd << ", same : " << correctkey.compare(keyPredictd);
}