/*
 * A magic box with p rows and r columns is initially filled with silver. If we
 * invoke a method 'addMagicOperation' which turns the silver at index (r, c)
 * into gold.
 * 
 * Given N set of indices to work up on, find the number of gold-blocks which
 * are formed after each addMagicOperation.
 * 
 * A gold-block is a block of gold cells connected horizontally and vertically
 * and surrounded by silver. Consider all four edges of the magic box are
 * surrounded by silver.
 * 
 * Input Format: -------------- Line-1: Three space separated integers p, r ,
 * and n (number of add Magic Operations) Next N lines: Two space separated
 * integers, cell to perform addMagicOperation
 * 
 * Output Format: -------------- Print a list of numbers, number of gold-blocks
 * formed after each addMagicOperation
 * 
 * 
 * Sample Input-1: ----------------- 3 3 5 0 0 0 1 1 2 2 1 1 1
 * 
 * Sample Output-1: ----------------- [1, 1, 2, 3, 1]
 * 
 * Explanation: ----------- Initially, the magic box is filled with silver.
 * (Assume 0 represents silver and 1 represents gold).
 * 
 * 0 0 0 0 0 0 0 0 0
 * 
 * Operation #1: addMagicOperation(0, 0) turns the silver at cell[0][0] into
 * gold.
 * 
 * 1 0 0 0 0 0 Number of Gold-blocks = 1 0 0 0
 * 
 * Operation #2: addMagicOperation(0, 1) turns the silver at cell[0][1] into
 * gold.
 * 
 * 1 1 0 0 0 0 Number of Gold-blocks = 1 0 0 0
 * 
 * Operation #3: addMagicOperation(1, 2) turns the silver at cell[1][2] into
 * gold.
 * 
 * 1 1 0 0 0 1 Number of Gold-blocks = 2 0 0 0
 * 
 * Operation #4: addMagicOperation(2, 1) turns the silver at cell[2][1] into
 * gold.
 * 
 * 1 1 0 0 0 1 Number of Gold-blocks = 3 0 1 0
 * 
 * Operation #5: addMagicOperation(1, 1) turns the silver at cell[1][1] into
 * gold.
 * 
 * 1 1 0 0 1 1 Number of Gold-blocks = 1 0 1 0
 * 
 * 
 * 
 */

import java.util.*;

public class DisjointSetUnion {

    static int offset = 23; // Random prime number;
    static int graph[];

    static void unite(int x, int y) {
        int px = find_par(x);
        int py = find_par(y);
        if (px != py) {
            graph[px] = py;
        }
    }

    static int find_par(int x) {
        while (x != graph[x]) {
            graph[x] = graph[graph[x]];
            x = graph[x];
        }
        return x;
    }

    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        int m, n, q;
        m = ip.nextInt();
        n = ip.nextInt();
        q = ip.nextInt();
        ArrayList<Integer> ans = new ArrayList<Integer>();

        graph = new int[m * n + 1];
        for (int i = 0; i < m * n + 1; i++) {
            graph[i] = -1;
        }

        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };
        int count = 0;

        for (int i = 0; i < q; i++) {
            int x, y;
            x = ip.nextInt();
            y = ip.nextInt();

            int val = x * n + (y + 1);
            graph[val] = val;
            count++;

            for (int j = 0; j < 4; j++) {
                int xdash = x + dx[j];
                int ydash = y + dy[j];

                if (xdash < 0 || ydash < 0 || xdash >= m || ydash >= n)
                    continue;
                int newVal = xdash * n + (ydash + 1);

                if (graph[newVal] == -1)
                    continue;
                if (find_par(val) != find_par(newVal)) {
                    unite(val, newVal);
                    count--;
                }
            }
            ans.add(count);
        }
        System.out.println(ans);

    }
}