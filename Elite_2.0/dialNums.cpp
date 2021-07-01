/*
Given a nokia phone,with the following dialpad.
		1 2 3
		4 5 6
		7 8 9
		* 0 #
And You are given an L band to dial the number,  
Using the L band you can dial the number as follows, 
You can start with any digit,
	if you are at digit 1, next digit you can choose {6,8}
	if you are at digit 2, next digit you can choose {7,9}
	if you are at digit 3, next digit you can choose {4,8}
	and so on..

Now your task is to find how many distinct numbers of length N you can dial.

Note: Numbers should contain only digits, {* , #} -> not allowed.
Answer should be modulo 1000000007.

Input Format:
-----------------
An integer N, length of numbers
 
Output Format:
------------------
Print an integer, number of distinct numbers you can dial.


Sample Input-1:
---------------
1

Sample Output-1:
----------------
10

Explanation:
-------------
To dial a number of length 1, you can dial all digits.


Sample Input-2:
---------------
2

Sample Output-2:
----------------
20

Explanation:
------------
To dial a number of length 2, the possible numbers are
{04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94}

Sample Input-3:
---------------
5

Sample Output-3:
----------------
240


*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

vector<vector<int>> reachables = {
    {4, 6},
    {6, 8},
    {7, 9},
    {4, 8},
    {0, 3, 9},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {4, 2},
    {4, 6}};

long long ans;

int main()
{
    int n;
    cin >> n;
    vector<int> prev(10, 1);
    vector<int> next(10, 0);

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int x : reachables[i])
            {
                next[i] += prev[x];
                next[i] %= mod;
            }
        }
        prev = next;
        next = vector<int>(10, 0);
    }

    for (int x : prev)
    {
        // cout << x << " ";
        ans += x;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}

/*
t2[0]=t1[6]+t1[4];
                t2[1]=t1[6]+t1[8];
                t2[2]=t1[7]+t1[9];
                t2[3]=t1[4]+t1[8];
                t2[4]=t1[0]+t1[3]+t1[9];
                t2[5]=0;
                t2[6]=t1[0]+t1[1]+t1[7];
                t2[7]=t1[2]+t1[6];
                t2[8]=t1[1]+t1[3];
                t2[9]=t1[2]+t1[4];
*/