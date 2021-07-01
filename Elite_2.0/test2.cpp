/*
Pramod is working on patterns.
He is given a pattern P of length N-1, He needs to construct a list L[] of length N.
And the list L[] has to construct using the integers from 1 to N only.

To construct the list, He defined a rule set as follows based on the pattern P:
	- if P[i] == 'A', then L[i] < L[i+1].
	- if P[i] == 'D', then L[i] > L[i+1].
	- And the L[] should be lexicographically smallest.

You will be given the pattern P of length N-1 
Your task is to construct the list using the pattern and 
according to the rules set by Pramod.

NOTE:
Can you solve the problem in O(N) time complexity?

Input Format:
-------------
A string, the pattern consist of only A and D alphabets.

Output Format:
--------------
Print the list, according to the given pattern.


Sample Input-1:
---------------
DAA

Sample Output-1:
----------------
[2, 1, 3, 4]

Explanation:
------------
Using the sequence DAA there are more than one way of creating the list:
for example: [2,1,3,4], [3,1,2,4], [4,1,2,3].
According to the given info, the result should be lexicographically smallest.
So the answer is [2,1,3,4].


Sample Input-2:
---------------
ADA

Sample Output-2:
----------------
[1, 3, 2, 4]

Explanation:
------------
Using the sequence ADA there are more than one way of creating the list:
for example: [1,3,2,4], [1,4,2,3], [2,4,1,3], [2,3,1,4]..etc
According to the given info, the result should be lexicographically smallest.
So the answer is [1,3,2,4].


*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    int sz = arr.size();

    cout << "[";
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i];
        if (i != sz - 1)
            cout << ", ";
    }
    cout << "]\n";
}

void rev(vector<int> &arr, int left, int right)
{
    while (left <= right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main()
{
    string str;
    cin >> str;
    str.push_back('#');
    int n = str.size();

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    // int i = 0;

    int left = n - 2;
    int right = n - 1;
    while (left >= 0)
    {
        if (str[left] == 'A')
        {
            rev(arr, left + 1, right);
            right = left;
        }
        left--;
    }

    rev(arr, left + 1, right);
    print(arr);

    return 0;
}