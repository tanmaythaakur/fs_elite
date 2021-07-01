/*
Ramesh and Suresh are best friends. 
They decided to play a word game.

The game rules are as follows:
	- The game board shows a word W consist of two characters only A and B.
	- You are allowed to replace a pair of neighbour letters AA with BB in W.
	- Finally, The one who failed to replace the letters will lose the game.

You can assume that Ramesh will start playing the game always.

Your task is to determine if Ramesh can guarantee a win.
Print 'true', if Ramesh guarantee a win, otherwise, print 'false'.

Input Format:
-------------
A string W, word.

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
AAABAAAA

Sample Output-1:
----------------
true

Explanation:
------------
Given word is AAABAAAA 
Ramesh -> AAABBBAA 
Now whatever the pair Suresh replaced with BB, 
one more replace is possible for Ramesh
So, there is a guarantee for Ramesh to win.

Sample Input-2:
---------------
AAAAAA

Sample Output-2:
----------------
true


Sample Input-3:
---------------
AAABAAA

Sample Output-3:
----------------
false

*/
#include <bits/stdc++.h>
using namespace std;

string str;

bool canwin()
{
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == 'A' && str[i + 1] == 'A')
        {
            str[i] = 'B';
            str[i + 1] = 'B';
            bool ans = !canwin();
            str[i] = 'A';
            str[i + 1] = 'A';
            if (ans)
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> str;

    if (canwin())
    {
        cout << "true\n";
    }
    else
        cout << "false\n";
    return 0;
}