#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<int>> matrix;

bool special(vector<vector<int>> &rows, vector<vector<int>> &cols, int rr, int cc, int side)
{
    int sum = rows[rr][cc + side] - rows[rr][cc], d1 = 0, d2 = 0;

    for (int k = 0; k < side; k++)
    {
        d1 += matrix[rr + k][cc + k];
        d2 += matrix[rr + side - 1 - k][cc + k];
        if (rows[rr + k][cc + side] - rows[rr + k][cc] != sum || cols[rr + side][cc + k] - cols[rr][cc + k] != sum)
            return false;
    }
    return d1 == sum && d2 == sum;
}

int biggest()
{
    vector<vector<int>> rows(r, vector<int>(c + 1));
    vector<vector<int>> cols(r + 1, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            rows[i][j + 1] = rows[i][j] + matrix[i][j];
            cols[i + 1][j] = cols[i][j] + matrix[i][j];
        }
    }
    for (int side = min(r, c); side > 1; side--)
    {
        for (int i = 0; i <= r - side; i++)
        {
            for (int j = 0; j <= c - side; j++)
            {
                if (special(rows, cols, i, j, side))
                    return side;
            }
        }
    }
    return 1;
}

int main()
{
    cin >> r >> c;
    matrix.assign(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << biggest() << endl;

    return 0;
}
