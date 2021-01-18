/*

A dangerous virus "ebola" is spreading across african countries.
Few people stand in a form of p*q grid, some positions in the grid are empty.

The grid is represented with three values 0,1, 2.
Where
	- 0 indicates an empty position,
	- 1 indiactes a healthy person , or
	- 2 indiactes an infected person.
	
Every minute, any healthy person who is 4-directionally adjacent to an infected 
person becomes infected.

Your task is to find out the minimum amount of time in minutes that the virus 
takes to spread among all the people in that grid.

If this is impossible, return -1.

NOTE:
4-directions are Up, Down, Left, Right.

Input Format:
-------------
Line-1: Two integers P and Q, size of the grid.
Next P lines: contains Q space separated integers, either 0, 1, or 2.

Output Format:
--------------
An integer, the minimum amount of time in minutes


Sample Input-1:
---------------
3 3
2 1 1
1 1 0
0 1 1

Sample Output-1:
----------------
4

Explanation-1:
--------------
There is an infected person at position (0, 0).
In the first minute: people in (0, 1) and (1, 0) positions are infected.
In the second minute: people in (0, 2) and (1, 1) positions are infected.
In the third minute: person in (1, 2) position is infected.
In the fourth minute: person in (2, 2) position is infected.


Sample Input-2:
---------------
3 3
2 1 1
0 1 1
1 0 1

Sample Output-2:
----------------
-1

Explanation-2:
--------------
The healthy person in the bottom left corner (row 2, column 0) is never infected, 
because infection only happens 4-directionally.

Sample Input-3:
---------------
1 2
0 2

Sample Output-3:
----------------
0

Explanation-3: 
-------------
Since there is already no healthy person at minute 0, the answer is just 0.


*/

import java.util.*;

class VirusSucks {
    private static int rows, cols;
    private static int[][] ppl;
    private static boolean vis[][];
    private static Queue<int[]> q = new LinkedList<int[]>();

    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        rows = ip.nextInt();
        cols = ip.nextInt();
        ppl = new int[rows][cols];
        vis = new boolean[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ppl[i][j] = ip.nextInt();
                if (ppl[i][j] == 2) {
                    int pos[] = { i, j };
                    q.add(pos);
                    vis[i][j] = true;
                }
            }
        }

        int ans = -1;

        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };

        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int currPos[] = q.peek();
                q.remove();

                int x = currPos[0], y = currPos[1];

                for (int j = 0; j < 4; j++) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];

                    if (newX < 0 || newY < 0 || newX >= rows || newY >= cols)
                        continue;

                    if (vis[newX][newY] || ppl[newX][newY] != 1)
                        continue;

                    int neibr[] = { newX, newY };
                    q.add(neibr);
                    vis[newX][newY] = true;
                    ppl[newX][newY] = 2;
                }
            }

            ans++;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (ppl[i][j] == 1) {
                    System.out.println(-1);
                    return;
                }
            }
        }
        System.out.println(ans);
    }
}
