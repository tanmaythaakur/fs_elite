
/*


Pramod is working on words. He used to remove all the duplicate letters from a
word.

Pramod is given a word W. His task to remove all theduplicated letters from W,
in such a way that the resulatant word R, contains no duplicate letters and all
distinct letters from W should be there in R.and R should appear first in the 
dictionary order. 

Input Format:
-------------
A String, the word W.

Output Format:
--------------
Print a String, resulatant word R.


Sample Input-1:
---------------
cbadccb 

Sample Output-1:
----------------
adcb

Sample Input-2:
---------------
silicosis

Sample Output-2:
----------------
ilcos    

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int n = str.size();
    vector<bool> taken(26, false);
    unordered_map<char, int> last;
    stack<char> st;

    // last occurence
    for (int i = n - 1; i >= 0; i--)
    {
        if (!last.count(str[i]))
            last[str[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int idx = str[i] - 'a';
        char ch = str[i];

        if (taken[idx])
            continue;

        while (!st.empty() && (st.top() > ch) && (last[st.top()] > i))
        {
            taken[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(ch);
        taken[idx] = true;
    }

    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}