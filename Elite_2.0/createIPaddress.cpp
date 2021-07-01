/*
Pramod is planning to design a program, which helps to create 
the IP addresses posssible from a given string S, 
where each IP address should be valid.

It is guaranteed that S contains only digits.

Can you help pramod in designing such program, which returns all possible IP addresses.
Print the answer in lexicographic order.

NOTE:
-----

- A valid IP address consists of exactly four integers, 
each integer is between 0 and 255, separated by single dots 
and cannot have leading zeros
- IP Addresses are said to be valid if it falls in the range 
from 0.0.0.0 to 255.255.255.255

- IP addresses like [123.012.234.255 , 123.234.345.34] are invalid.

Input Format:
-------------
A string S, contains only digits [0-9].

Output Format:
--------------
Print all possible IP addresses which are valid.


Sample Input-1:
---------------
23323311123

Sample Output-1:
----------------
[233.233.11.123, 233.233.111.23]


Sample Input-2:
---------------
12345678

Sample Output-2:
----------------
[1.234.56.78, 12.34.56.78, 123.4.56.78, 123.45.6.78, 123.45.67.8]


Sample Input-3:
---------------
02550255

Sample Output-3:
----------------
[0.25.50.255, 0.255.0.255]


*/

#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void print()
{
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]\n";
}

bool valid(string curr)
{
    string parts;
    for (char ch : curr)
    {
        if (ch == '.')
        {
            // cout << parts << endl;
            if (parts.size() > 1 && parts[0] == '0')
                return false;
            if (parts.size() > 0)
            {
                // cout << "Parts 1: " << parts << endl;
                int num = stoi(parts);
                if (num > 255)
                    return false;
            }
            parts = "";
        }
        else
            parts += ch;
    }

    // cout << parts << endl;
    if (parts.size() > 1 && parts[0] == '0')
        return false;
    if (parts.size() > 0)
    {
        // cout << "Parts 2: " << parts << endl;
        int num = stoi(parts);
        if (num > 255)
            return false;
    }

    return true;
}

void solve(string str, string curr, int idx, int dotCount)
{
    if (dotCount == 4 && idx == str.size())
    {
        // cout << curr << endl;
        if (valid(curr))
        {
            curr.pop_back();
            ans.push_back(curr);
        }
        return;
    }

    string part = "";

    for (int i = idx; i < str.size(); i++)
    {
        part += str[i];
        curr += str[i];
        curr += ".";
        solve(str, curr, i + 1, dotCount + 1);
        curr.pop_back();
        if (part.size() > 2)
            break;
    }
}

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    if (n < 4 || n > 12)
    {
        cout << "[]" << endl;
        return 0;
    }
    string curr = "";
    int dotCount = 0;
    solve(str, curr, 0, dotCount);
    print();

    return 0;
}