/*
Cardano is a famous mathematician. working on numbers.
Given a number N, which is the product of all the digits of a number.
You need to find such smallest number S.

Your task is to help Mr Cardano to find smallest number S, 
where the product of all the digits of S should be equal to N.
If it is not possible to create S with in range of integer, print 0.


Input Format:
-------------
An integer N

Output Format:
--------------
Print an integer, smallest number S.


Sample Input-1:
---------------
36

Sample Output-1:
----------------
49


Sample Input-2:
---------------
147

Sample Output-2:
----------------
377


Sample Input-3:
---------------
22

Sample Output-3:
----------------
0


*/
#include <bits/stdc++.h>
using namespace std;

int n;
string ans;

void solve()
{
    vector<int> factors;

    for (int i = 9; i >= 2; i--)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n != 1)
    {
        cout << 0 << endl;
        return;
    }
    sort(factors.begin(), factors.end());
    for (int x : factors)
    {
        cout << x;
    }
    cout << endl;
}

int main()
{
    cin >> n;
    solve();
    return 0;
}