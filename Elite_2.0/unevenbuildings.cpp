/*
There is a row of buildings constructed by Raj Group Ltd.

The civil engineer planned to construct the buildings in ascending order 
of their heights, but there is a group of contiguous buildings not constructed 
according to the plan, remove such group of buildings from that row of buildings 
(can be empty), so the buildings in the row are in sorted order of their heights.

Your task is to find and return the number of buildings in such group.

Input Format:
-------------
Line-1: An integer N, length of array.
Line-2: N space separated integers, heights of the buildings.

Output Format:
--------------
Print an integer, the minimum of group of buildings.


Sample Input-1:
---------------
8
2 3 5 12 2 4 5 7
Sample Output-1:
----------------
3

Explanation:
------------
The minimum group of builings in a row, you can remove is [5, 12, 2] or 
[12, 2, 4]  of length 3. 
 - the remaining buildings with the heights after removal will be [2, 3, 4, 5, 7],
 OR [2, 3, 5, 5, 7], which are in ascending order.


Sample Input-2:
---------------
6
9 7 5 4 2 1

Sample Output-2:
----------------
5

Explanation:
------------
The minimum group of builings in a row, you can remove is [7, 5, 4, 2, 1] or  
[9, 7, 5, 4, 2]  of length 5. 


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0, right = n - 1;

    while (left < right && arr[left] <= arr[left + 1])
        left++;

    if (left == n - 1)
    {
        cout << 0 << endl;
        return 0;
    }

    while (right > left && arr[right] >= arr[right - 1])
        right--;

    int ans = min(n - left - 1, right);

    int i = 0, j = right;

    for (int i = 0; i <= left; i++)
    {
        if (arr[i] <= arr[j])
        {
            ans = min(ans, j - i - 1);
        }
        else if (j < n - 1)
        {
            j++;
        }
        else
            break;
    }
    cout << ans << endl;

    return 0;
}

// 2 3 5 12 2 4 5 7
/*
a1 = 0+1+1+1
st1 [2, 2, 4, 5, 7]

a2 = 0+1+1+1
st2 = [12, 5, 3, 2]

6
1 5 3 2 3 5
*/