/*
Chitti built a mini robot 'Tiny', which is used to transform
the given string S into a target string T.

Tiny is allowed to perform the given steps to transform S into T:
	- Add a letter to S at any place.
	- Remove any letter from S.
	- Substitute a letter in S with another letter.

Your task is to write a program for Tiny to transform S into T
in minimum number of steps. and return the count of steps.

Input Format:
-------------
Two space separated strings S and T, consist of lowercase letters only.

Output Format:
--------------
Print an integer, minimum number of steps required to transform S into T.


Sample Input-1:
---------------
energy synergy

Sample Output-1:
----------------
2

Explanation:
-----------
energy -> senergy (add 's')
senergy -> synergy (substitute 'y' in place of 'e')


Sample Input-2:
---------------
treatment basement

Sample Output-2:
----------------
5

Explanation:
-----------
treatment -> tretment (remove 'a')
tretment -> trement (remove 't')
trement -> arement (substitute 'a' in place of 't')
arement -> asement (substitute 's' in place of 'r')
asement -> basement (add 'b')

*/
#include <bits/stdc++.h>
using namespace std;

string s, t;
int slen, tlen;
vector<vector<int>> dp;

int rec(int m, int n)
{
    if (n == 0 || m == 0)
        return abs(m - n);

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (s[m - 1] == t[n - 1])
    {
        return dp[m][n] = rec(m - 1, n - 1);
    }
    else
    {
        return dp[m][n] = 1 + min({rec(m - 1, n), rec(m, n - 1), rec(m - 1, n - 1)});
    }
}

int main()
{
    // string s, t;
    cin >> s >> t;
    // int lcs = LCS(s, t);
    slen = s.size();
    tlen = t.size();

    dp.assign(slen + 1, vector<int>(tlen + 1, -1));

    int ans = rec(slen, tlen);

    cout << ans << endl;

    return 0;
}