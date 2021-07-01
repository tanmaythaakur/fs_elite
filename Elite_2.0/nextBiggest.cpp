/*
You are given a list of digits( 0 to 9) digits[].
A number is formed using the given order of the list.
for example: given list is [1,3,2], then number is 132.

Find the next biggest number in the lexographic order using 
the same list of digits, by using the each digit in the list only once,
and print the digit list of such biggest number.

If such biggest number is not possible, 
print the smallest lexographic order of the digits.

Input Format:
-------------
Line-1 : An integer N, number of digits.
Line-2 : N space separated integers, list of digits.

Output Format:
--------------
Print an integer list.


Sample Input-1:
---------------
4
1 2 4 3

Sample Output-1:
----------------
[1, 3, 2, 4]


Sample Input-2:
---------------
4
4 3 2 1

Sample Output-2:
----------------
[1, 2, 3, 4]


*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]\n";
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int i;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    for (i = n - 1; i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
            break;
    }

    if (i == 0)
    {
        print(arr);
        return 0;
    }

    int x = arr[i - 1], smallest = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] > x && arr[j] < arr[smallest])
            smallest = j;
    }
    swap(arr[smallest], arr[i - 1]);
    sort(arr.begin() + i, arr.end());

    print(arr);

    return 0;
}