/*
Kiran is given a string S, and an integer N.
Kiran wants to find the longest substring which has following properties:
	- the substring of S should be maximum in length, and 
	- should contains atmost N distint characters in it.
	
Can you help Kiran to find the longest substring 'ls' with above properties,
and return the length of the substring 'ls'.

Input Format:
-------------
Line-1: A string S
Line-2: An integer N, number of distinct characters.

Output Format:
--------------
Print an integer, lenth of longest substring with atmost N distinct characters.


Sample Input-1:
---------------
philippines
3

Sample Output-1:
----------------
6

Sample Input-2:
---------------
abaccdbcca
2

Sample Output-2:
----------------
3

*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp;

int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;

    int ansStart = -1, ansEnd = -1;
    int len = 0;
    int st = 0, ed = 0;
    int n = str.size();

    while (ed < n)
    {
        mp[str[ed]]++;
        while (mp.size() > k)
        {
            mp[str[st]]--;
            if (mp[str[st]] == 0)
                mp.erase(str[st]);
            if (ed - st > len)
            {
                len = ed - st;
                ansStart = st;
                ansEnd = ed;
            }
            st++;
        }

        ed++;
    }
    len = max(len, ed - st);
    // string ans = "";
    // for (int i = ansStart; i < ansEnd; i++)
    // {
    //     ans += str[i];
    // }
    // cout << ans << endl;
    cout << len << endl;

    return 0;
}