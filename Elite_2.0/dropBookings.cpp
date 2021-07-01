/*
UBER driver has a vehicle, daily he used go in only one direction.
Capacity of the vehicle is S (no of seats except driver seat), 

Given a list of N bookings, booking[i]= [ num_customers, pickup, drop ].
booking indicates, number of customers to pick up, and pick up, droping points.

Initially the vehicle is empty.

Return true if and only if it is possible to pick up and drop off all customers 
of all bookings.

Input Format:
-------------
Line-1 -> Two integers N and S, number of bookings and number of seats in the vehicle.
Next N Lines -> three space separated integers, num_customers, pickup point, 
                dropping point

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
2 5
2 1 5
3 3 7

Sample Output-1:
----------------
true


Sample Input-2:
---------------
2 4
2 1 5
3 3 7

Sample Output-2:
----------------
false


Sample Input-3:
---------------
3 11
3 2 7
3 7 9
8 3 9

Sample Output-3:
----------------
true

*/

#include <bits/stdc++.h>
using namespace std;

int timings[1024];

int main()
{
    int n, s;
    cin >> n >> s;
    int cust, pickup, drop;
    for (int i = 0; i < n; i++)
    {
        cin >> cust >> pickup >> drop;

        for (int j = pickup; j < drop; j++)
            timings[j] += cust;
    }

    for (int numCust : timings)
    {
        if (numCust > s)
        {
            cout << "false\n";
            return 0;
        }
    }
    cout << "true\n";

    return 0;
}