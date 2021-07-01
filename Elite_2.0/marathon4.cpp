#include <bits/stdc++.h>
using namespace std;

// wrong. Working on that

int main()
{
    int n;
    cin >> n;
    int x, y;
    vector<vector<int>> points;
    vector<int> dp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int x : dp)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}