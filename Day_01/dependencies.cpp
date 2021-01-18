
/*

EA Sports, developed a video game.
They designed a game in such a way that, there are L number of levels from 1 to L.
There are D number of dependencies where each dependency[m] = [ Xm, Ym ], 
represents a prerequisite relationship, that is, in order to play level-Ym,  
you must have completed the level-Xm . 

In one day you can complete any number of levels as long as you have completed 
all the prerequisites levels in the game. 

You cannont play a level-Ym which has some prerequisite level-Xm on same day.

Write a method to return the minimum number of days to complete all the levels 
in the game. If there is no way to complete all the levels, return -1.


Input Format:
-------------
Line-1: An integer L, number of levels.
Line-2: An integer D, number of dependencies.
Next D lines: Two space separated integers, Xm and Ym.

Output Format:
--------------
An integer, the minimum number of days to complete all the levels in the game.


Sample Input-1:
---------------
3
2
1 3
2 3

Sample Output-1:
----------------
2

Explanation-1:
--------------
On the first day, levels 1 and 2 are completed. 
On the second day, level 3 is completed.


Sample Input-2:
---------------
3
3
1 2
2 3
3 1

Sample Output-2:
----------------
-1

Explanation-2:
-------------
No level can be completed because they depend on each other.
*/


#include<bits/stdc++.h>
using namespace std;
#define INF 9999999

int dfs(vector<vector<int>> &graph, int src, vector<bool> &vis)
{
    vis[src] = true;
    int curr = 0;
    
    for(int nbr: graph[src]) {
        curr = max(curr, dfs(graph, nbr, vis));
    }
    curr++;
    return curr;
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> graph(n+1, vector<int>());
    int m; cin >> m;
    vector<int> inDeg(n+1);
    vector<bool> vis(n+1);
    
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        graph[y].push_back(x);
        inDeg[x]++;
    }
    
    
    int ans = INF;
    
    for(int i=1; i<=n; i++) {
        if(vis[i] == false && inDeg[i] == 0) {
            ans = min(ans, dfs(graph, i, vis));
        }
    }
    if(ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    
    return 0;
}



