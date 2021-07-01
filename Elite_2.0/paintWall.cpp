/*
You are decorating a side wall with balloons.
You have an unlimited set of ballons of three different colors.

The decoration should have N rows of 3 balloons each. 
You have to make sure that no two adjacent balloons have the same colour.
both vertically and horizontally.

Return the number of ways you can decorate the wall,  
the answer must be computed modulo 10^9 + 7

Input Format:
-------------
An integer N

Output Format:
--------------
Print an integer as outpur, number of ways to decorate.


Sample Input-1:
---------------
1

Sample Output-1:
----------------
12

Explanation:
------------
Suppose the colors are, B, G, R. Given N is 1
RBR	BRB	GRB
RBG	BRG	GRG
RGR	BGR	GBR
RGB	BGB	GBG


Sample Input-2:
---------------
2

Sample Output-2:
----------------
54



*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int pat1 = 6, pat2 = 6;

    // from above patterns, pat1 is aba type, and pat2 is abc type
    // from one aba type, we can form 3 aba type and 2 abc type
    // from one abc type, we can form 2 aba type and 2 abc type
    for (int i = 1; i < n; i++)
    {
        long long fromPat1 = (pat1 * 3) % mod + (pat2 * 2) % mod;
        long long fromPat2 = (pat1 * 2) + (pat2 * 2) % mod;

        pat1 = fromPat1 % mod;
        pat2 = fromPat2 % mod;
    }

    int ans = int((long long)(pat1 + pat2) % mod);

    cout << ans << endl;

    return 0;
}