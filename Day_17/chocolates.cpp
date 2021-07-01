#include <bits/stdc++.h>
using namespace std;

int uknapsack(vector<int> &arr, int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];

    // Recursive solution, pass dp as a parameter
    // if (n == 0)
    // {
    //     return sum == 0;
    // }
    // if (sum == 0)
    //     return 1;

    // if (dp[n][sum] != -1)
    //     return dp[n][sum];

    // if (arr[n - 1] <= sum)
    // {
    //     dp[n][sum] = fknapsack(arr, dp, n, sum - arr[n - 1]) + fknapsack(arr, dp, n - 1, sum);
    // }
    // else
    // {
    //     dp[n][sum] = fknapsack(arr, dp, n - 1, sum);
    // }
    // return dp[n][sum];
}

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
    int count = uknapsack(arr, n, s);

    cout << count << endl;
    return 0;
}