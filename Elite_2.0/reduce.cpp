/*
Sampoornesh Babu is learning arithmatics.
His teacher given him a task to find the minimum number of operations
required to convert a given integer I to 1.

Sampoornesh is allowed to perform the following operations:
	- If I is even, convert I with I/2 .
	- In I is odd, convert I with either I+1 or I-1.

Now it's your task to help Sampoornesh Babu to find and print
the minimum number of operations required.

Input Format:
-------------
An integer I.

Output Format:
--------------
Print an integer, the minimum number of operations required.


Sample Input-1:
---------------
10

Sample Output-1:
----------------
4

Explanation:
------------
10 -> 5 -> 4-> 2 -> 1.


Sample Input-2:
---------------
15

Sample Output-2:
----------------
5

Explanation:
------------
15 -> 16 -> 8 -> 4 -> 2 -> 1.

*/
#include <bits/stdc++.h>
using namespace std;

int num;

int howMany(int n)
{
    if (n == 1)
        return 0;

    if (n % 2 == 0)
    {
        return 1 + howMany(n / 2);
    }
    else
    {
        return 1 + min(howMany(n + 1), howMany(n - 1));
    }
}

int main()
{
    cin >> num;
    cout << howMany(num) << endl;
    return 0;
}