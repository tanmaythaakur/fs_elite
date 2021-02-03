#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int start = 0, end = 0;
    int ans = 0;

    while (end < n)
    {
        if (arr[end] == 1)
        {
            end++;
            continue;
        }
        while (k <= 0)
        {
            ans = max(ans, end - start);
            if (arr[start] == 1)
            {
                start++;
                continue;
            }
            k++;
            start++;
        }
        k--;
        end++;
    }
    ans = max(ans, end - start);
    cout << ans << endl;

    return 0;
}