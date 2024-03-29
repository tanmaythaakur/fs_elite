/*
Every year after Lord Ganesh chaturthi, Ganesh idols of various sizes are to be immersed 
in the Hussain Sagar lake. There is a need of  'K' cranes to immerse idols into lake.

There are 'N' number of Ganesh idols with the given sizes, 
where 'i'th idol size is idolsize[i].
and each Crane can handle maximum size 'S'. 

Each Crane carries at most 2 idols at the same time, 
and the sum of the sizes of those idols should be <= 'S'.
Find out the minimum number of Cranes 'K' required to perform immersion of all the idols.

Note: It is guaranteed that a Crane can carry one ganesh idol of any zize.

Input Format:
----------------
Line-1 -> Two Integers, N and S
Line-2 -> N space separated integers, idolsize[]

Output Format:
------------------
Print an integer as result.


Sample Input-1:
-------------------
4 3
3 2 2 1

Sample Output-1:
---------------------
3

Explanation: 
----------------
3 Cranes required (1, 2), (2) and (3).

Sample Input-2:
-------------------
4 5
3 5 3 3

Sample Output-2:
---------------------
4

Explanation: 
----------------
4 Cranes required (3), (3), (4), (5)


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, temp;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    sort(arr.begin(), arr.end());
    int first = 0, last = n - 1;

    while (first < last)
    {
        if (arr[first] + arr[last] <= k)
        {
            first++;
            last--;
        }
        else
        {
            last--;
        }
        ans++;
    }
    if (first == last)
    {
        ans++;
    }

    cout << ans << endl;

    return 0;
}
