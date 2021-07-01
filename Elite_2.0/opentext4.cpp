/*
You are provided a string of characters(lowercase only),
You can change the order of the characters of the string.
After changing the order, the resultant string should be 
no two immidiate characters equal.

Return true, if you are able to find such resultant string, 
Otherwise false.

Input Format:
-------------
A String S

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
aaabd

Sample Output-1:
----------------
true

Sample Input-2:
---------------
aaab

Sample Output-2:
----------------
false

*/

#include <bits/stdc++.h>
using namespace std;

int freq[26];

int main()
{
    string str;
    cin >> str;

    for (char ch : str)
    {
        freq[ch - 'a']++;
    }

    // freq, char
    pair<int, char> lastUsed = {-1, '$'};
    priority_queue<pair<int, char>> pq;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            pq.push({freq[i], i + 97});
        }
    }

    string res = "";

    while (!pq.empty())
    {
        pair<int, char> curr = pq.top();
        pq.pop();
        res += curr.second;
        int newFreq = curr.first - 1;
        if (lastUsed.first > 0)
            pq.push(lastUsed);
        lastUsed = {newFreq, curr.second};
    }

    // cout << res << endl;

    if (res.size() == str.size())
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}