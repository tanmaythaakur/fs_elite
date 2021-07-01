/*
Sridhar brought his latest Apple iPhone 12 pro. He started his conversation 
with one of his friend on WhatsApp with list of words.

Now it’s our task to find and return what are the most common words 
in the list of words he used in sorted order based on occurrence from 
largest to smallest. If any of words he used are having same occurrence 
then consider the lexicographic order.

You will be given a list of words, you need to print top P number of 
most common used words as described in the statement. 

Input Format:
-------------
Line-1: comma separated line of words, list of words.
Line-2: An integer P, number of words to display. 

Output Format:
--------------
Print P number of most common used words.


Sample Input-1:
---------------
ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are,case
3

Sample Output-1:
----------------
[are, case, egg]



Sample Input-2:
---------------
ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are
3

Sample Output-2:
----------------
[are, egg, case]

*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split(string line)
{
    vector<string> ret;
    string temp;
    for (char ch : line)
    {
        if (ch == ',')
        {
            ret.push_back(temp);
            temp = "";
        }
        else
            temp += ch;
    }
    ret.push_back(temp);
    return ret;
}

void print(vector<string> &ans)
{
    int n = ans.size();
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
        if (i != n - 1)
            cout << ", ";
    }
    cout << "]\n";
}

int main()
{
    string line;
    getline(cin, line);
    vector<string> strs = split(line);
    int k;
    cin >> k;
    unordered_map<string, int> mp;

    for (string s : strs)
    {
        mp[s]++;
    }

    vector<pair<string, int>> freqs;
    for (auto p : mp)
    {
        freqs.push_back(p);
    }
    sort(freqs.begin(), freqs.end(), [&](pair<string, int> a, pair<string, int> b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a < b;
    });

    vector<string> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(freqs[i].first);
    }
    print(ans);

    return 0;
}