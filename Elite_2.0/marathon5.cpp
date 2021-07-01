#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    vector<vector<int>> ones;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                ones.push_back({i, j});
            }
        }
    }

    int gsum = 1e5;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                int sum = 0;
                for (auto dist : ones)
                {
                    sum += abs(dist[0] - i) + abs(dist[1] - j);
                }
                if(gsum > sum) {
                    gsum = sum;
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    cout << gsum << endl;

    return 0;
}