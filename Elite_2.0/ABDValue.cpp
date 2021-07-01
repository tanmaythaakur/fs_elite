/*

Sumanth has an idea to calculate the ABD value of a string.
An ABD value is defined as the absolute diffrence between
the most occurance count of a charcter and the least occurance count 
of another character in the given string.

Sumanth is given a string S,
He wants to find out, the sum of ABD values of all the substrings of S,
where ABD > 0.

Your task is to help Sumanth to find total ABD value of substrings of S.

Input Format:
-------------
A String S

Output Format:
--------------
Print an integer, sum of ABD of all the strings of S


Sample Input-1:
---------------
abbcc

Sample Output-1:
----------------
5

Explanation: 
------------
The substrings with non-zero ABD are as follows:
Substring and ABD value -> "abb"-1,"abbc"-1,"abbcc"-1,"bbc"-1,"bcc"-1
The total sum of ABD is, 5


Sample Input-2:
---------------
abcbabc

Sample Output-2:
----------------
15

Explanation: 
------------
The substrings with non-zero ABD are as follows:
substring and ABD value -> "abcb"-1,"abcba"-1,"abcbab"-2,"abcbabc"-1,"bcbabc"-2
"bcbab"-2, "bcba"-1, "bcb"-1, "cbab"-1,"cbabc"-1,"bab"-1, "babc"-1.
The total sum of ABD is, 15

*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    int sz = arr.size();

    cout << "[";
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i];
        if (i != sz - 1)
            cout << ", ";
    }
    cout << "]\n";
}

int main()
{
    string str;
    cin >> str;

    int n = str.size();
    unordered_map<char, int> mp;
    int abd = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            string substring = str.substr(i, j - i);
            mp.clear();
            // cout << substring << endl;
            for (char ch : substring)
                mp[ch]++;

            int maxi = INT_MIN, mini = INT_MAX;
            for (auto x : mp)
            {
                maxi = max(maxi, x.second);
                mini = min(mini, x.second);
            }
            abd += maxi - mini;
            // cout << maxi << " " << mini << endl;
            // cout << "******************" << endl;
        }
    }
    cout << abd << endl;

    return 0;
}