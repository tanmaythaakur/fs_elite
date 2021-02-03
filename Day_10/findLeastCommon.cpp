#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> bag(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> bag[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int curr = bag[0][i];
        bool flag = false;
        for (int j = 1; j < m; j++)
        {
            if (!binary_search(bag[j].begin(), bag[j].end(), curr))
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << curr << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
