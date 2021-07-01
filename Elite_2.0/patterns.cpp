#include<bits/stdc++.h>
using namespace std;

int ans;

void dfs(vector<vector<int>> &required, int currNum, int len, int mini, int maxi, vector<bool> &vis)
{
    if(len > maxi) return count;
    

    vis[currNum] = true;
    int tempAns = 0;
    for(int nbr = 1; nbr <= 9; nbr++) {
        if(!vis[nbr] && required[currNum][nbr] == 0 || vis[required[currNum][nbr]]) {
            tempAns += dfs(required, nbr, len+1, mini, maxi, vis);
        }
    }
    vis[currNum] = false;
    return tempAns;
}



void solve(int m, int n)
{
    vector<vector<int>> required(10, vector<int>(10, 0));
    required[1][3] = required[3][1] = 2;
    required[1][7] = required[7][1] = 4;
    required[1][9] = required[9][1] = 5;
    required[2][8] = required[8][2] = 5;
    required[4][6] = required[6][4] = 5;
    required[7][9] = required[9][7] = 8;
    required[3][9] = required[9][3] = 6;
    required[3][7] = required[7][3] = 5;
    vector<bool> vis(10, false);

    int temp1 = dfs(required, 1, 1, m, n, vis);

    ans += dfs(required, 5, 1, m, n, vis);
    ans += dfs(required, 2, 1, m, n, vis) * 4;

    cout << ans << endl;
}


int main()
{
    int m, n;
    cin >> m >> n;
    
    solve(m, n);
    return 0;
}