#include <bits/stdc++.h>
using namespace std;

int ans;
// Needs work
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int st = 0, ed = n - 1;

    while (st < n - 1)
    {
        if (arr[st] > arr[st + 1])
        {
            break;
        }
        st++;
    }

    if (st == n - 1)
    {
        cout << 0 << endl;
        return 0;
    }

    while (ed >= 0)
    {
        if (arr[ed] < arr[st])
        {
            break;
        }
        ed--;
    }
    cout << st << " " << ed << endl;

    ans = ed - st + 1;

    cout << ans << endl;
    return 0;
}