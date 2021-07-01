#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<int> lastSeen(26, -1);

    for (int i = 0; i < str.size(); i++)
    {
        lastSeen[str[i] - 'a'] = i;
    }

    vector<bool> taken(26, false);

    stack<char> st;

    for (int i = 0; i < str.size(); i++)
    {
        char curr = str[i];

        if (taken[curr - 'a'])
            continue;

        while (!st.empty() && st.top() > curr && lastSeen[st.top() - 'a'] > i)
        {
            taken[st.top() - 'a'] = false;
            st.pop();
        }
        taken[curr - 'a'] = true;
        st.push(curr);
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(begin(ans), end(ans));
    cout << ans << endl;

    return 0;
}