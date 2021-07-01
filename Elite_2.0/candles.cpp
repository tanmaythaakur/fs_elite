/*
In a Maths class, the math teacher given a task to her students, 
She is given an unlimit set of candles, the candles are in the form of digits 
from [0-9]. The task is, students have to form the natural numbers from M to N, 
(where M < N) using the candles given to them. The students have to find and 
return the number of digit-D shaped candles used to form the natural numbers
between M and N, where M and N are inclusive.

You will be given three integers D, M, and N.
Your task is to help the students to find the number of digit-D shaped candles used.

Input Format:
-------------
Three space separated integers, D, M, and N

Output Format:
--------------
Print an integer, the number of times digit-D shaped candles used.


Sample Input-1:
---------------
2 15 25

Sample Output-1:
----------------
7

Explanation:
------------
Numbers contains digit-2 in them are 20,21,22,23,24,25. So total of 7.

Sample Input-2:
---------------
3 21 39

Sample Output-2:
----------------
12

*/
#include <bits/stdc++.h>
using namespace std;

int d, m, n;
int ans;

void dfs(int num, int num_of_D)
{
    if (num > n)
        return;

    if (num >= m && num_of_D)
    {
        ans += num_of_D;
    }

    for (int i = 0; i <= 9; i++)
    {
        dfs(num * 10 + i, num_of_D + (i == d));
    }
}

int main()
{
    cin >> d >> m >> n;

    for (int i = 1; i <= 9; i++)
    {
        dfs(i, i == d);
    }

    cout << ans << endl;
    return 0;
}
