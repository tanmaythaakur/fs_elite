/*
A forest is represented as a square grid consist of 0's an 1's only.
Few people stuck in the forest, where 1's are indicate people, 
and 0's are indicate as trees. A person cannot move from the tree.

You want to save people, a person can be saved, if he/she connected to other person 
who is at the boundary of forest
If 'a' is connected to 'b' and 'b' is connected to 'c',
then you can consider that 'a' is also connected to 'c'. 
They can connected in 4 directions only (up, right, left and down).

You need to find out the number of persons, whom cannot be saved from 
the given forest grid.


Input Format:
-------------
Line-1 -> An integer N, size of the grid N*N
next N lines -> N space separated integers(0's and 1's)

Output Format:
--------------
Print an integer as your result


Sample Input-1:
---------------
5
0 0 1 1 0
1 0 0 1 0
0 0 1 0 0
0 1 1 0 1
1 0 0 1 0

Sample Output-1:
----------------
3

Explanation:
------------
In the given grid, 1's at (2,2), (3,1), (3,2) positions are not connected 
to the boundary. So, number of people cannot be saved are 3

Sample Input-2:
---------------
5
0 0 1 1 0
1 0 0 1 0
0 0 1 1 0
0 1 1 0 1
1 0 0 1 0

Sample Output-2:
----------------
0

Explanation:
------------
In the given grid, each 1 is either at the boundary or connceted to 1 at boundary.
So, number of people cannot be saved are '0'




*/

#include <bits/stdc++.h>
using namespace std;

void change(vector<vector<int>> &arr, int x, int y, vector<vector<bool>> &vis)
{
    if (x < 0 || y < 0 || x >= arr.size() || y >= arr.size())
        return;

    if (vis[x][y] || arr[x][y] == 0)
        return;

    arr[x][y] = 0;
    vis[x][y] = true;

    change(arr, x + 1, y, vis);
    change(arr, x - 1, y, vis);
    change(arr, x, y + 1, vis);
    change(arr, x, y - 1, vis);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    vector<vector<bool>> vis(n, vector<bool>(n));
    // memset(vis, false, sizeof(vis));

    // top row
    for (int i = 0; i < n; i++)
        if (arr[0][i])
            change(arr, 0, i, vis);

    // bottom row
    for (int i = 0; i < n; i++)
        if (arr[n - 1][i])
            change(arr, n - 1, i, vis);

    // left side
    for (int i = 0; i < n; i++)
        if (arr[i][0])
            change(arr, i, 0, vis);

    // right side
    for (int i = 0; i < n; i++)
        if (arr[i][n - 1])
            change(arr, i, n - 1, vis);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << arr[i][j] << " ";
            count += arr[i][j];
        }
        // cout << endl;
    }
    cout << count << endl;
    return 0;
}