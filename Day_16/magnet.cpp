
/*
Given a flat surface of m*n size, each position contains either empty '0', 
a Iron ball 'B' or Metal Block 'M' (The Metal block is an anti magnetic block), 
Your task is to find the maximum Iron Balls you can attarct by using a Magnet.

The Magnet attarcts all the iron balls in the same row and column from their 
positions until the Metal Block. since the Metal block is an anti magnetic block.

Note: You can only put the magnet at an empty position.


Input Format:
-------------
Line-1 -> Two Integers, M and N, size of the grid
Next M Lines -> N space separated characters, allowed characters '0', 'B', 'M'


Output Format:
--------------
Print an integer, maximum Iron Balls you can attarct by using a Magnet


Sample Input-1:
---------------
3 4
0 B 0 0 
B 0 M B
0 B 0 0

Sample Output:
--------------
3 

Explanation: 
------------
For the given grid,

0 B 0 0 
B 0 M B
0 B 0 0

Placing a Magnet at (1,1) attacts 3 iron balls.
 

*/

// Passes 7/8 cases

#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> arr)
{
    for (auto t : arr)
    {
        for (int x : t)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> mat(m, vector<char>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<vector<int>> arr(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 'M')
                count = 0;
            arr[i][j] += count;
            if (mat[i][j] == 'B')
                count++;
        }
    }
    // print(arr);

    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (mat[i][j] == 'M')
                count = 0;
            arr[i][j] += count;
            if (mat[i][j] == 'B')
                count++;
        }
    }
    // print(arr);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (mat[j][i] == 'M')
                count = 0;
            arr[j][i] += count;
            if (mat[j][i] == 'B')
                count++;
        }
    }
    // print(arr);

    for (int j = 0; j < n; j++)
    {
        int count = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            if (mat[i][j] == 'M')
                count = 0;
            arr[i][j] += count;
            if (mat[i][j] == 'B')
                count++;
        }
    }
    // print(arr);

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << arr[i][j] << " ";
            ans = max(ans, arr[i][j]);
        }
        // cout << endl;
    }
    cout << ans << endl;

    return 0;
}