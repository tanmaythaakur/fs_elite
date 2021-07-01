/*
Manoj is given a box full of balls with several colors, 
each colored ball is uniquely identified by a number.

All the balls are arranged in a line randomly.
He is given the arrangement as an array of numbers, colored balls.
He has to form the subarray of size S from left to right, and 
find the number of diffferent colors in each subarray.

Your task is to help Manoj to find the number of different colored balls 
in each subarray and print them as an array.

Input Format:
-------------
Line-1: Two integers N and S, number of balls, size of subarray.
Line-2: N space separated integers, colors of the balls in the line.

Output Format:
--------------
Print an array of integers.


Sample Input-1:
---------------
7 3
2 3 4 3 3 2 4

Sample Output-1:
----------------
[3, 2, 2, 2, 3]


Sample Input-2:
---------------
8 4
1 2 2 2 2 3 4 5

Sample Output-2:
----------------
[2, 1, 2, 3, 4]


*/
#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindow(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;

    int left = 0, right = 0, counter = 0;
    int n = arr.size();
    vector<int> ans;

    while (right < n)
    {
        mp[arr[right]]++;
        if (mp[arr[right]] == 1)
            counter++;
        if (right - left + 1 < k)
        {
            right++;
            continue;
        }
        ans.push_back(counter);
        mp[arr[left]]--;
        if (mp[arr[left]] == 0)
            counter--;
        left++;
        right++;
    }

    return ans;
}

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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = slidingWindow(arr, k);
    print(ans);
    return 0;
}