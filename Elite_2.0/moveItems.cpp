#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<string> matrix;
    string temp;

    for (int i = 0; i < r; i++)
    {
        cin >> temp;
        matrix.push_back(temp);
    }

    vector<string> mat(c, string(r, '#'));

    for (int i = 0; i < r; i++)
    {
        int j = 0;
        for (j = 0; j < c; j++)
        {
            mat[j][r - i - 1] = matrix[i][j];
        }
        // reverse(mat[j - 1].begin(), mat[j - 1].end());
    }

    // for (string &s : mat)
    // {
    //     cout << s << endl;
    // }

    // cout << endl
    //      << endl;

    // working till above

    // start from second last row, if element below it is a space then make make below element as I
    // and curr element as space

    swap(r, c);
    // cout << r << " " << c << endl;

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 'I')
            {
                int nextRow = i + 1;
                while (nextRow < r && mat[nextRow][j] == 'S')
                {
                    mat[nextRow - 1][j] = 'S';
                    mat[nextRow][j] = 'I';
                    nextRow++;
                }
            }
        }
    }

    for (string &row : mat)
    {
        cout << row << endl;
    }

    return 0;
}