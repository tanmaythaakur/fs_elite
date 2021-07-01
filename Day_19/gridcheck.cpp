/*
    Prof. Neil Gogte asked Mr.Nagi Reddy to create a grid with set of words in
such a way that if you read the word in i-th row and the word in i-th column
should be equal.
Mr. Nagi Reddy created the grid accordingly.

Now it’s your aim to check whether Mr.Nagi Reddy’s grid has satisfied
conditions given by Prof. Neil Gogte.

If satisfied, print "true". Otherwise print "false"

Constraints:
-------------
 N should be a positive integer.
 0 < word[i].length <= N
word[i+1].length <= word[i].length

Input Format:
-------------
Line-1 -> an integer N, number of words
Line-2 -> N space separated words.

Output Format:
--------------
Print a boolean result.


Sample Input-1:
---------------
4
kmit made idol tell

Sample Output-1:
----------------
true

Explanation:
-------------
Given grid looks as follows:
k m i t
m a d e
i d o l
t e l l
if you read the words in every i-th row and i-th column,
both the words are same. so return true.


Sample Input-2:
---------------
5
abcde bcde cde de e

Sample Output-2:
----------------
true

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<string> extra;
    int pt = 0;

    while (true)
    {
        bool flag = false;
        string temp;

        for (string st : arr)
        {
            if (pt < st.length())
            {
                temp += st[pt];
                flag = true;
            }
        }
        if (flag == false)
            break;
        extra.push_back(temp);
        pt++;
    }

    for (int i = 0; i < n; i++)
    {
        if (extra[i] != arr[i])
        {
            cout << "false\n";
            return 0;
        }
    }
    cout << "true" << endl;

    return 0;
}