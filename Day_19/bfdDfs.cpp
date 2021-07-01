/*
Brahmi and his gang was chased by group of police officers, unfortunately they 
all got locked up in a building consist of M*N rooms in the form of a grid. 
All the rooms are connected with  the adjacent rooms both horizontally and vertically.
There are few rooms for them to escape called as safe zones. 

Now help Brahmi and his gang to reach the safe zones in the building.

In the Building, the rooms classified as follows:
    -1 -> Danger zone (they should not enter into it).
     0 -> Safe Zone (room to escape)
    -2 -> a thief

Now create a method to print the grid after performing following step: 
Fill each room of the Brahmi and his gang with the distance to its nearest safe zone.
If it is impossible to reach a safezone, fill with '-2' only.

Input Format:
-------------
Line-1 -> two integers M and N, size of the grid of rooms.
Next M Lines -> N space separated integers, from this set [-2,-1,0] only.

Output Format:
--------------
Print an integer as result.


Sample Input-1:
---------------
4 4
-2 -1 0 -2
-2 -2 -2 -1
-2 -1 -2 -1
0 -1 -2 -2

Sample Output-1:
----------------
3 -1 0 1
2 2 1 -1
1 -1 2 -1
0 -1 3 4



*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

// vector<vector<bool>> vis(1000, vector<bool>(1000));

bool outside(vector<vector<int>> &hotel, int x, int y)
{
    bool ans = x < 0 || y < 0 || x >= hotel.size() || y >= hotel[0].size();
    return ans;
}

void dfs(vector<vector<int>> &hotel, int x, int y, int depth)
{
    if (outside(hotel, x, y))
        return;
    if (hotel[x][y] == -1)
        return;

    // cout << "been here: " << x << " " << y << endl;
    if (hotel[x][y] == -2)
    {
        hotel[x][y] = depth;
    }
    else
    {
        hotel[x][y] = min(hotel[x][y], depth);
    }

    if (hotel[x][y] == depth)
        for (int i = 0; i < 4; i++)
        {
            dfs(hotel, x + dx[i], y + dy[i], depth + 1);
        }
}

// void dfs(vector<vector<int>> &hotel, int x, int y)
// {
//     // vector<vector<bool>> vis(hotel.size(), vector<bool>(hotel[0].size()));
//     vis[x][y] = true;
//     for (int i = 0; i < 4; i++)
//     {
//         dfsUtil(hotel, x + dx[i], y + dy[i], 1);
//     }
// }

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> hotel(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> hotel[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (hotel[i][j] == 0)
            {
                dfs(hotel, i, j, 0);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << hotel[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}