#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int maxLetter = 0;
    string maximum = "";
    vector<int> indices;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= maxLetter)
        {
            maxLetter = str[i];
            indices.push_back(i);
        }
    }

    for (int idx : indices)
    {
        maximum = max(str.substr(idx), maximum);
    }
    cout << maximum << endl;

    return 0;
}