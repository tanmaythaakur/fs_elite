/*
Amith decided go on a holiday trip. 
Given a map of N holiday spots numbered 0,1,2,.. N-1, map shows the connecting routes
between the holiday sopts, the routes are bidirectional, and
the connecting routes are indicates as routes[i] = [from , to , distance ]. 
He can travel only a certian distance D.

Your task is to find the holiday spot H with the smallest number of holiday spots
that are reachable from H and whose distance is at most D, 

If there are multiple holiday spots, return H with the greatest number.


Input Format:
-------------
Line-1 : Three integers, N number of holiday spots, R is the number of connecting 
        routes and D is the distance can travel.
Next R lines : Three space separated integers, from , to and distance.

Output Format:
--------------
Print an integer, holiday spot.


Sample Input-1:
---------------
4 4 4
0 1 3
1 2 1
1 3 4
2 3 1

Sample Output-1:
----------------
3


Explanation:
------------
Distance can travel= 4,

From			Reachable sopts
-------------------------------------
Holiday-spot 0 -> [Holiday-spot 1, Holiday-spot 2] 
Holiday-spot 1 -> [Holiday-spot 0, Holiday-spot 2, Holiday-spot 3] 
Holiday-spot 2 -> [Holiday-spot 0, Holiday-spot 1, Holiday-spot 3] 
Holiday-spot 3 -> [Holiday-spot 1, Holiday-spot 2] 

Holiday-spots 0 and 3 have 2 reachable Holiday-spots at a distance = 4, 
but we have to return Holiday-spot 3 since it has the greatest number.


Sample Input-2:
---------------
5 6 2
0 1 2
0 4 8
1 2 3
1 4 2
2 3 1
3 4 1

Sample Output-2:
----------------
0

Explanation:
------------
Distance can travel= 2,

From			Reachable sopts
-------------------------------------
Holiday-spot 0 -> [Holiday-spot 1] 
Holiday-spot 1 -> [Holiday-spot 0, Holiday-spot 4] 
Holiday-spot 2 -> [Holiday-spot 3, Holiday-spot 4] 
Holiday-spot 3 -> [Holiday-spot 2, Holiday-spot 4]
Holiday-spot 4 -> [Holiday-spot 1, Holiday-spot 2, Holiday-spot 3]

Holiday-spots 0 has 1 reachable Holiday-spot at a distance = 2, 

*/
#include <bits/stdc++.h>
using namespace std;
#define INF 9999999

vector<vector<int>> mat;

int main()
{
    int n, e, d;
    cin >> n >> e >> d;
    mat.assign(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                mat[i][j] = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        mat[a][b] = w;
        mat[b][a] = w;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int cnt = 999999;
    int ans = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] <= d && mat[i][j] != 0)
                count++;
        }
        if (count < cnt)
        {
            cnt = count;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}