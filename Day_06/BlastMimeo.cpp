#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;

    stack<char> st1;
    stack<int> st2;

    for (char ch : str)
    {
        if (st1.empty())
        {
            st1.push(ch);
            st2.push(1);
            continue;
        }

        if (ch == st1.top())
        {
            st1.push(ch);
            int temp = st2.top();
            st2.pop();
            st2.push(temp + 1);
        }
        else
        {
            st1.push(ch);
            st2.push(1);
        }
        if (st2.top() == k)
        {
            st2.pop();
            for (int i = 0; i < k; i++)
            {
                st1.pop();
            }
        }
    }

    string ans;
    while (!st1.empty())
    {
        ans += st1.top();
        st1.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}