#include <bits/stdc++.h>
using namespace std;

int ax, ay, sx, sy, n, ans;

bool isTree(vector<vector<int>> arr, int x, int y)
{
    return (x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 1);
}

void dfs(vector<vector<int>> &arr, int x, int y, bool up, bool down, bool left, bool right, int currAns)
{
    if (isTree(arr, x, y))
        return;
    if (x == sx && y == sy)
    {
        ans = min(ans, currAns);
        return;
    }

    if (isTree(arr, x + 1, y))
    {
    }
    else if (isTree(arr, x - 1, y))
    {
    }
    else if (isTree(arr, x, y + 1))
    {
    }
    else if (isTree(arr, x, y - 1))
    {
    }
    else
    {
        if (up)
        {
            dfs(arr, x - 1, y, up, down, left, right, currAns + 1);
        }
        else if (down)
        {
            dfs(arr, x + 1, y, up, down, left, right, currAns + 1);
        }
        else if (left)
        {
            dfs(arr, x, y - 1, up, down, left, right, currAns + 1);
        }
        else
        {
            dfs(arr, x, y + 1, up, down, left, right, currAns + 1);
        }
    }
}

int main()
{
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    cin >> ax >> ay >> sx >> sy;

    dfs(arr, ax, ay, true, false, false, false, 0);
    dfs(arr, ax, ay, false, true, false, false, 0);
    dfs(arr, ax, ay, false, false, true, false, 0);
    dfs(arr, ax, ay, false, false, false, true, 0);

    cout << ans << endl;

    return 0;
}