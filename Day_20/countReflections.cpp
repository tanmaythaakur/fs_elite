#include <bits/stdc++.h>
using namespace std;

// Incorrect

vector<int> digits = {0, 1, 6, 8, 9};
unordered_map<int, int> mp = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
int n, ans = 0;

int getXY(int num)
{
    int rev = 0;
    int temp = num;
    while (temp)
    {
        rev = rev * 10 + mp[temp % 10];
        temp /= 10;
    }
    // cout << rev << " ";

    temp = rev;
    int r = 0;
    while (temp)
    {
        r = r * 10 + mp[temp % 10];
        temp /= 10;
    }
    temp = r;
    r = 0;
    while (temp)
    {
        r = r * 10 + temp % 10;
        temp /= 10;
    }
    // cout << r << endl;
    return r;

    // 16 -> 91 -> 61
    // 19 ->
}

void dfs(int n, int idx, int curr)
{
    if (curr * 10 + digits[idx] > n)
        return;
    int newCurr = curr * 10 + digits[idx];
    int rev = getXY(newCurr);
    if (rev != newCurr)
    {
        ans++;
        cout << newCurr << " " << rev << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        dfs(n, i, newCurr);
    }
}

int main()
{
    cin >> n;
    cout << getXY(16) << endl;
    for (int i = 1; i < 5; i++)
    {
        dfs(n, i, 0);
    }
    cout << ans << endl;
    return 0;
}

// 1691 -> 1961 -> 1691
// 6 -> 9 -> 9