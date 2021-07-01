/*
Sampoornesh Babu is working with Strings.
He is trying to form a palindrome using two strings P and Q.
The rules to form the palindrome are as follows:
	- Divide the strings P and Q into two parts, and length of P and Q are same.
	- Division of P and Q should be done at same index position.
	- After Division P -> P1 + P2 and Q -> Q1 + Q2, where + indicates concatenation.
	- Now, check whether P1 + Q2 or Q1 + P2 forms a palindrome or not.
	- if palindrome is formed print 'true', otherwise 'false'. 

For Example: 'job' can be divided in the following ways:
""+"job", "j"+"ob",  "jo"+"b", "job"+"".

Your task is to help Sampoornesh Babu to find whether palindrome can be 
formed with the strings P and Q.

Input Format:
-------------
Two space separated strings P and Q

Output Format:
--------------
Print a boolean value, whether can you form a palindrome or not.


Sample Input-1:
---------------
mortal carrom

Sample Output-1:
----------------
true

Explanation:
------------
Divide P="mortal" and Q="carrom" at index 3 as follows:
    P -> "mor" + "tal", P1 = "mor" and P2 = "tal"
    Q -> "car" + "rom", Q1 = "car" and Q2 = "rom"

P1 + Q2 = "morrom" is a palindrome,so print true.


Sample Input-2:
---------------
romans carrom

Sample Output-2:
----------------
false


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

bool isPalindrome(string str)
{
    int left = 0, right = str.size() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
            return false;

        left++;
        right--;
    }
    return true;
}

void solve(string &a, string &b)
{
    int n = a.size();

    for (int i = 0; i <= n; i++)
    {
        string pref1 = a.substr(0, i);
        string suff1 = a.substr(i, n - i);

        // cout << pref1 << " " << suff1 << endl;

        string pref2 = b.substr(0, i);
        string suff2 = b.substr(i, n - i);

        // cout << pref2 << " " << suff2 << endl;
        // cout << "*****************************" << endl;
        if (isPalindrome(pref1 + suff2) || isPalindrome(pref2 + suff1))
        {
            cout << "true\n";
            return;
        }
    }
    cout << "false\n";
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << isPalindrome("ABBA");
    solve(str1, str2);

    return 0;
}