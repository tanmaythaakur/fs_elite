/*
Now a days, everyone is used type the words using short-forms,
A short-form can be created by replacing non-intersected substrings 
with their respective lengths.

e.g., elite can be written as follows:
    - e3e (by replacing lut with 3), 
    - el2e (by replacing it with 2), 
    - 3t1 (by replacing eli and e with 3 and 1).
etc.


You will be given a word.
Your task is to find all possible short-fomrs of the given word, 
and print them as a list of lexicographic order.


Input Format:
-------------
A string W, the word.

Output Format:
--------------
Print the list of possible short-forms of W in lexographic order. 


Sample Input-1:
---------------
kmit

Sample Output-1:
----------------
[4, 3t, 2i1, 2it, 1m2, 1m1t, 1mi1, 1mit, k3, k2t, k1i1, k1it, km2, km1t, kmi1, kmit]


Sample Input-2:
---------------
cse

Sample Output-2:
----------------
[3, 2e, 1s1, 1se, c2, c1e, cs1, cse]

*/
#include <bits/stdc++.h>
using namespace std;

string str;
vector<string> forms;

void dfs(string &str, string curr, int idx)
{
    if (idx == str.size())
    {
        forms.push_back(curr);
        // cout << curr << " ";
        return;
    }

    curr.push_back(str[idx]);
    dfs(str, curr, idx + 1);
    curr.pop_back();

    int count = 1;
    if (curr.size() > 0)
    {
        if (curr.back() <= '9' && curr.back() >= '0')
        {
            count += (curr.back() - '0');
            curr.pop_back();
        }
    }

    curr.push_back(count + '0');
    dfs(str, curr, idx + 1);
    // curr.pop_back();
}

void solve(string str)
{
    string curr;
    int idx = 0;
    dfs(str, curr, idx);
}

int main()
{
    cin >> str;
    solve(str);
    sort(forms.begin(), forms.end());
    cout << "[";
    string ans = "";
    for (auto x : forms)
    {
        ans += x;
        ans += ", ";
    }
    ans.pop_back();
    ans.pop_back();
    cout << ans;
    cout << "]\n";
    return 0;
}