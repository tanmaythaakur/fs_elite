/*
Major Ajay Krishna and Prasad garu are working on a military operation at 
Himachal Pradesh. They are given an operation to defuse the bomb, and they have 
time falling short.

Their informer will provide them with a round-shape lock of length ‘L’, 
where L number of integers on the lock and a clue ‘C’.

To defuse the bomb they have to restore the original state of the lock, 
by restoring every integer on lock. All the integers must be restored in the 
same way based on the clue.

Its your task to help Major Ajay Krishna, to restore the original code on the lock, 
to defuse the bomb.

To restore the lock to its original state, you have to follow these instructions:
	- If C > 0, restore every i-th number with the sum of the next C integers.
	- If C < 0, restore every i-th number with the sum of the previous C integers.
	- If C == 0, restore every i-th number with 0.
	
As the lock is in round shpae, the next element of lock[n-1] is lock[0], 
and the previous element of lock[0] is lock[n-1].


Input Format:
-------------
Line-1: Two space separated integers L, C.
Line-2: L space separated integers, integers on the Lock.

Output Format:
--------------
Print the original state of the lock.


Sample Input-1:
---------------
5 2
2 5 9 4 7

Sample Output-1:
----------------
[14, 13, 11, 9, 7]


Sample Input-2:
---------------
5 0
1 5 6 3 2

Sample Output-2:
----------------
[0, 0, 0, 0, 0]

*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    int n = arr.size();
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n - 1)
            cout << ", ";
    }
    cout << "]\n";
}

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans(n);
    if (c == 0)
    {
        print(ans);
        return 0;
    }

    if (c > 0)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int sum = 0;
            for (int k = 0; k < c; k++, j++)
            {
                if (j == n)
                    j = 0;
                sum += arr[j];
            }
            ans[i] = sum;
        }
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            int j = i - 1;
            int sum = 0;
            for (int k = 0; k < abs(c); k++, j--)
            {
                if (j == -1)
                {
                    j = n - 1;
                }
                sum += arr[j];
                // cout << sum << endl;
            }
            ans[i] = sum;
        }
    }
    print(ans);

    return 0;
}