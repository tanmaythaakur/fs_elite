#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> up(n), down(n);

    for (int i = 0; i < n; i++)
        cin >> up[i];

    for (int j = 0; j < n; j++)
        cin >> down[j];

    unordered_map<int, int> mp;

    for (int x : up)
        mp[x]++;

    for (int i = 0; i < n; i++)
    {
        if (up[i] == down[i])
            continue;

        if (mp[down[i]] == 0)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}