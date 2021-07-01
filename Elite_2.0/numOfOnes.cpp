#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str = "122";
    int ans = 0;

    int i = 2;
    bool ones = true;

    while (str.size() < n)
    {
        if (ones)
        {
            str.append(str[i] - '0', '1');
        }
        else
        {
            str.append(str[i] - '0', '2');
        }
        ones = !ones;
        i++;
    }
    // cout << str << endl;
    int count = 0;
    for (char ch : str.substr(0, n))
    {
        count += (ch == '1');
    }
    cout << count << endl;

    return 0;
}