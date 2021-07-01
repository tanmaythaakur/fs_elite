/*
Bunny is playing with binary strings.
He wants to divide a binary string B into 3 parts, each part length is >= '1',
when we combine the 3 parts will result the string B.
eg. B is divided as d1, d2, d3. if we combine d1, d2 and d3 should result B.

Your task is to find the number of ways to divide the Binary String B 
into 3 parts, where each part should contain equal number of 1's.

The answer may be too large, return it modulo 10^9 + 7.

Input Format:
-------------
A string B, a binary string B.

Output Format:
--------------
Print an integer, number of ways to break B.


Sample Input-1:
---------------
01010010

Sample Output-1:
----------------
6

Explanation:
------------
There are six ways to break S into 3 parts 
where each part contain the equal number of  1's.
01 | 01 | 0010
01 | 010 | 010
01 | 0100 | 10
010 | 1 | 0010
010 | 10 | 010
010 | 100 | 10


Sample Input-2:
---------------
010010

Sample Output-2:
----------------
0


*/
#include <bits/stdc++.h>
using namespace std;
#define mod (int)1e9 + 7

int solve(string str)
{
    int count = 0;
    int ans = 0;
    for (char ch : str)
        count += ch - '0';

    if ((count % 3 != 0))
        return 0;

    int onesPerPart = count / 3;

    unordered_map<int, int> mp;
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum += str[i] - '0';
        if (sum == 2 * onesPerPart && mp.count(onesPerPart) && i > 0 && i < str.size() - 1)
            ans += mp[onesPerPart];
        mp[sum]++;
    }

    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << solve(str) << endl;
    // cout << ans << endl;
    return 0;
}