/*
Kohinoor diamond is robbed by Hrithik,
He kept the diamond in a suitcase, the suitcase has a lock with 4 circular wheels, 
and each wheel consist of 0-9 digits in the order 0,1,2,3,4,5,6,7,8,9 only.
You can rotate a wheel from 0 to 9 or 9 to 0.

As the diamond is most valuable, the lock has some traps,
if anybody try to unlock the suitcase and reached any one of the traps,
the suitcase will be blasted. And you will be dead.

Initially, the suitcase lock is set to 0000.
and you will be given the unlock key, your task to find and print
the minimum number of rotations required to unlock the suitcase.
If it is not possible to unlock the suitcase without blasting, print -1.

NOTE:
In one rotation you can choose any one wheel and 
rotate to its next or previous digit.


Input Format:
-------------
Line-1: space separated strings, each string of length 4 and contains only digits [0-9]
Line-2: A string, key to unlock.

Output Format:
--------------
Print an integer, the minimum number of rotations required to unlock.


Sample Input-1:
---------------
0302 0202 0203 2323 3003
0303 

Sample Output-1:
----------------
8

Explanation:
------------
To unlock the suitcase the valid rotations are as follows:
0000 > 1000 > 1100 > 1200 > 1201 > 1202 > 0202 > 0302 > 0303.


Sample Input-2:
---------------
6656 6676 6766 6566 5666 7666 6665 6667
6666 

Sample Output-2:
----------------
-1

Explanation:
------------
You can't unlock the suitcase.

*/
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &temp, char ch)
{
    string curr;
    int i = 0;
    vector<string> ans;
    while (i < temp.size())
    {
        if (temp[i] == ch)
        {
            ans.push_back(curr);
            curr = "";
        }
        else
            curr += temp[i];

        i++;
    }
    ans.push_back(curr);
    return ans;
}

int movesToReach(vector<string> &blastPoints, string &finalState)
{
    unordered_set<string> banned, beenThrough;
    for (string point : blastPoints)
    {
        banned.insert(point);
    }
    string initialState = "0000";
    queue<pair<string, int>> states;

    if (banned.count(initialState))
        return -1;

    states.push({initialState, 0});
    beenThrough.insert(initialState);

    while (!states.empty())
    {
        string curr = states.front().first;
        int count = states.front().second;
        states.pop();

        if (banned.count(curr))
        {
            continue;
            // cout << "CURR is banned: " << curr << endl;
        }

        if (curr == finalState)
        {
            // cout << "FROM HERE\n";
            return count;
        }
        count++;
        for (int i = 0; i < finalState.size(); i++)
        {
            string prev = curr;
            prev[i] = (prev[i] == '0') ? '9' : prev[i] - 1;
            string next = curr;
            next[i] = (next[i] == '9') ? '0' : next[i] + 1;

            if (!banned.count(prev) && !beenThrough.count(prev))
            {
                states.push({prev, count});
                beenThrough.insert(prev);
            }
            if (!banned.count(next) && !beenThrough.count(next))
            {
                states.push({next, count});
                beenThrough.insert(next);
            }
        }
    }
    return -1;
}

int main()
{
    string temp;
    getline(cin, temp);
    vector<string> blastPoints = split(temp, ' ');

    // for (string s : blastPoints)
    // {
    //     cout << s << " ";
    // }
    // cout << endl;

    string finalState;
    cin >> finalState;

    int ans = movesToReach(blastPoints, finalState);
    cout << ans << endl;

    return 0;
}