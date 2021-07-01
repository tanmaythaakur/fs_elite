#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int prev1 = (str[0] - '0') ^ 1;
    int prev2 = (str[0] - '0');

    int i = 0;
    int count1 = 0, count2 = 0;

    while (i < n)
    {
        if ((str[i] - '0') != prev1)
        {
            count1++;
        }
        i++;
        prev1 = prev1 ^ 1;
    }

    i = 1;
    while (i < n)
    {
        if ((str[i] - '0') != prev2 ^ 1)
        {
            count2++;
        }
        i++;
        prev2 = prev2 ^ 1;
    }
    cout << count1 << " " << count2 << endl;
    cout << min(count1, count2) << endl;
    return 0;
}