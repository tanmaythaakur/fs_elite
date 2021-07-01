/*
Given a bunch of baskets in a row, each basket contains few fruits in it.
You can select K number of baskets, one after other.
The selection of basket is either from beginning or from the end the row.

Return the maximum number of fruits you have after K baskets collected.

Input Format:
-------------
Line-1 -> Two integers N and K, N is no of baskets and K is the basket 
count you can pick.
Line-2 -> N space separated integers fruits[], fruits in each basket.

Output Format:
--------------
Print an integer, Maximum num of fruits you can collect.


Sample Input-1:
---------------
7 3
1 2 3 4 5 6 1

Sample Output-1:
----------------
12


Sample Input-2:
---------------
5 3
2 2 2 2 2

Sample Output-2:
----------------
6


Sample Input-3:
---------------
8 3
1 79 80 1 1 1 200 1

Sample Output-3:
----------------
202

*/

#include <bits/stdc++.h>
using namespace std;

int dp[1024][1024];

int select(vector<int> &arr, int low, int high, int k)
{
    if (k == 0)
        return 0;

    if (low > high)
        return 0;

    if (dp[low][high] != -1)
        return dp[low][high];

    return dp[low][high] = max(arr[low] + select(arr, low + 1, high, k - 1), arr[high] + select(arr, low, high - 1, k - 1));
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << select(arr, 0, n - 1, k) << endl;

    return 0;
}