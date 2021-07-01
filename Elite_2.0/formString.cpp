/*


Doesn't pass 

*/

#include <bits/stdc++.h>
using namespace std;

int alps[26];

string LCS(string s, string t)
{
    int m = s.size();
    int n = t.size();
    string res = "";
    vector<bool> taken(n);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            taken[j - 1] = true;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            taken[j - 1] = true;
            i--;
        }
        else
        {
            j--;
        }

        // cout << "stuck \n";
    }

    for (int i = 0; i < n; i++)
    {
        // cout << taken[i] << " ";
        if (!taken[i])
        {
            res += t[i];
        }
    }
    // cout << endl;
    return res;
}

int main()
{
    string s, t;
    cin >> s >> t;
    if (s.size() > t.size())
    {
        cout << -1 << endl;
    }

    for (char ch : s)
        alps[ch - 'a']++;

    for (char ch : t)
    {
        if (alps[ch - 'a'] == 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    int count = 1;
    while (true)
    {
        string newT = LCS(s, t);
        // cout << newT << endl;
        if (newT.size() == 0)
        {
            cout << count << endl;
            return 0;
        }
        t = newT;
        count++;
    }
    return 0;
}