/*
Basava interested playing with digits.
He wants create a set of integers of length N, using the digits[0-9].
The rules to create the integers are as follows:
	- digits in each integer are like d0,d1,d2...dn-1
	- and |d0-d1| = |d1-d2| = |d2-d3| ... |dn-2 - dn-1|= D

Basava is given two integers N and D, where N is length of the integer and 
D is the difference. Can you help Basava, to create such list of integers 
and print all the possible integers in ascending order


Note:
-----
Integers with leading 0's are not allowed


Input Format:
-------------
Two space separated integers N and K.

Output Format:
--------------
Print all the possible integers in ascending order.


Sample Input-1:
---------------
3 6

Sample Output-1:
----------------
[171, 282, 393, 606, 717, 828, 939]


Sample Input-2:
---------------
2 3

Sample Output-2:
----------------
[14, 25, 30, 36, 41, 47, 52, 58, 63, 69, 74, 85, 96]


*/

#include <bits/stdc++.h>
using namespace std;

set<int> container;
vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void recurr(int curr, int n, int d, int currLength)
{
    if (currLength == n)
    {
        container.insert(curr);
        return;
    }

    int lastdig = curr % 10;
    for (int x : arr)
    {
        if (abs(lastdig - x) == d)
        {
            int temp = curr * 10 + x;
            recurr(temp, n, d, currLength + 1);
        }
    }
}

int main()
{
    int n, d;
    cin >> n >> d;

    int curr = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        recurr(i, n, d, 1);
    }

    string ans = "[";
    for (int x : container)
    {
        ans += to_string(x) + ", ";
    }

    ans.pop_back();
    ans.pop_back();
    ans += "]";
    cout << ans << endl;
    return 0;
}