#include <bits/stdc++.h>
using namespace std;

void shakuniOP(vector<int> &oneD, int n)
{
    int ans = 0;
    queue<int> q;
    vector<bool> visited(n * n, false);

    int start = oneD[0] > -1 ? oneD[0] - 1 : 0;
    q.push(start);

    while (!q.empty())
    {
        int sz = q.size();

        for (int k = 0; k < sz; k++)
        {
            int currPos = q.front();
            q.pop();

            if (currPos == n * n - 1)
            {
                cout << ans << endl;
                return;
            }

            for (int x = currPos + 1; x < min(currPos + 7, n * n); x++)
            {
                int nextStop = oneD[x] == -1 ? x : oneD[x] - 1;
                if (!visited[nextStop])
                {
                    visited[nextStop] = true;
                    q.push(nextStop);
                }
            }
        }
        ans++;
    }

    // wont reach here. JFF.
    cout << "Shakuni left the chat!" << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    vector<int> oneD(n * n);
    int i = n - 1, j = 0, index = 0, inc = 1;

    while (index < n * n)
    {
        oneD[index++] = board[i][j];
        if (inc == 1 && j == n - 1)
        {
            inc = -1;
            i--;
        }
        else if (inc == -1 && j == 0)
        {
            inc = 1;
            i--;
        }
        else
        {
            j += inc;
        }
    }

    shakuniOP(oneD, n);

    return 0;
}