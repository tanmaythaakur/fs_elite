/*

Given a set of weights of n items weights[], and another item wieght w.
Your task is to check if the sum of weights of continuous subset is equal to 
one of the multiple of w, where subset size should be minimum 2.

For example: Mulitple of w means, w=3 then multiple of w are
3, 6, 9, 12, .... so on.

Print true, if such subset sum is possible.
Otherwise, print false.

Input Format:
-------------
Line-1 : Two integers n and w, number of weights and weight to match.
Line-2 : n space separated integers, weights of n items.

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
5 4
1 2 3 5 6

Sample Output-1:
----------------
false


Sample Input-2:
---------------
5 4
1 2 3 6 5

Sample Output-2:
----------------
true

Explanation: 
------------
sum of  continuous subset of weights [1,2,3,6]  equals to 12, multiple of 4.


*/

#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + arr[i];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= (i - 2); j++)
        {
            if ((pref[i] - pref[j]) % k == 0)
            {
                cout << "true" << endl;
                return 0;
            }
        }
    }

    cout << "false\n";

    return 0;
}

/*
    [1, 2, 4, 5, 6]
    [0, 1, 3, 7, 12, 18]
*/