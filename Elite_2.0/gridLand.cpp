/*
Few people travelling in N*N grid land.
and there are few traps set by local goons. Due to safety restrictions, 
people has to maximize the distance between the traps near to them.

You are given the current status of N*N grid containing values 0 and 1, 
where 0 represents a person and 1 represents trap, 
your task is to find a person's cell such that his/her distance to the 
nearest trap cell is maximized, and return the distance.

The distance used in this problem is the Manhattan distance: 
the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1| .

Input Format:
-------------
Line-1: An integer N, size of the square grid.
Next N lines: N space separated integers, grid[][] either 0 or 1.

Output Format:
--------------
An integer, maximum distance.


Sample Input-1:
---------------
3
1 0 1
0 0 0
1 0 1

Sample Output-1:
----------------
2

Explanation: 
------------
The person at (1, 1) is with distance 2 from all the traps.


Sample Input-2:
---------------
3
1 0 0
0 0 0
1 0 0

Sample Output-2:
----------------
3

Explanation: 
------------
The person at (1, 2) is with distance 3 from all the traps.


*/

#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<int>> dist(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                continue;
            grid[i][j] = INF;
            if (i > 0)
                grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
            if (j > 0)
                grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
        }
    }

    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[i][j] == 1)
                continue;
            if (i < n - 1)
                grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
            if (j < n - 1)
                grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);

            ans = max(ans, grid[i][j]);
        }
    }

    cout << ans - 1 << endl;
    return 0;
}