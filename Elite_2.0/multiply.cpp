/*
Babylonians invented muliplication of numbers.

You will be given two strings consist of digits only.
You have to perform the multiplication of these two strings using 
Babylonians approach, and return the result of multiplication of two strings.


Input Format:
-------------
Two space separated strings, num1 and num2.

Output Format:
--------------
Print the product of two strings num1 and num2.


Sample Input-1:
---------------
5 4 

Sample Output-1:
----------------
20


Sample Input-2:
---------------
121 432 

Sample Output-2:
----------------
52272

Note:
-----
	- Input should contain digits only, and should not contain leading 0's except 0.
	- Output will be in the range of integer only.
	- There will be no leading minus '-' symbol also.
	- Should not use built-in BigInteger library.
	- Should not convert the given strings into integers.

*/
#include <bits/stdc++.h>
using namespace std;

void multiply(string a, string b)
{
    int m = a.size(), n = b.size();
    int arr[m + n];
    memset(arr, 0, sizeof(arr));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int mul = (a[i] - '0') * (b[j] - '0');
            int pos1 = i + j, pos2 = i + j + 1;
            int sum = mul + arr[pos2];
            arr[pos1] += sum / 10;
            arr[pos2] = sum % 10;
        }
    }

    int i = 0;
    while (arr[i] == 0)
        i++;
    if (i == m + n)
    {
        cout << 0 << endl;
    }
    else
    {
        for (; i < m + n; i++)
            cout << arr[i];
        cout << endl;
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    multiply(a, b);
    return 0;
}