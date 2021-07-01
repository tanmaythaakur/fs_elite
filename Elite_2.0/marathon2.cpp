/*
In a class of N students, each student has different levels of IQ and 
different levels of patience. Each student is numbered from 0 to N-1.

To identify a student with number A, call him "Student A".

The teacher has created 'N-1' IQ pairs based on his observation of the students.
Each IQ pair (a,b), indicates Student 'a' is more  intelligent than Student 'b'.

The teacher also has a measure of  the patience of the students in the form of 
a list of  'N' integers. Where patience[i]=p, indicates Student 'i' has patience 'p'.

Now your task is to find the Result[i]= r, r is least patience student, 
among all the students who has more or equal IQ than Student[i], 
where 'i' is in range of [0..N-1].

Input Format:
-------------
Line-1 -> an integers N, number of students
Next 'N-1' lines -> two space seperated integers, indicates a pair (a, b).
Last Line -> N space seperated integers, patience levels of students

Output Format:
------------------
Print space seperated Result[i], where 'i' is in [0 .. N-1].


Sample Input-1:
-------------------
6
1 3
2 4
3 5
0 3
3 4
4 2 6 8 3 1

Sample Output-1:
---------------------
0 1 2 1 1 5

Explanation:
---------------
For Result[4]:
	Student 0, 1 has more IQ than Student 3, which has more IQ than Student 4.
	Among students 0,1,3,4,  'student 1' has less patience.
For Result[5]:
	Student 0, 1 has more IQ than Student 3, which has more IQ than Student 5.
	Among students 0,1,3,5,  'student 5' has less patience.


Sample Input-2:
-------------------
8
1 0
2 1
3 1
3 7
4 3
5 3
6 3
3 2 5 4 6 1 7 0

Sample Output-2:
---------------------
5 5 2 5 4 5 6 7

*/

#include <bits/stdc++.h>
using namespace std;

int minVal;
int vertex;

void dfs(vector<vector<int>> &graph, int src, vector<int> &p)
{
    if (p[src] < minVal)
    {
        minVal = p[src];
        vertex = src;
    }

    for (int nbr : graph[src])
    {
        dfs(graph, nbr, p);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    int x, y;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        graph[y].push_back(x);
    }

    vector<int> p(n), res(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    for (int i = 0; i < n; i++)
    {
        minVal = 1e5;
        dfs(graph, i, p);
        res[i] = vertex;
    }

    for (int x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}