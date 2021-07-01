/*
You are playing a shooting game.
There are N bottles hanging to a rod, i-th bottle numbered bottle[i].

If you shoot i-th bottle, you will get bottle[i-1]*bottle[i]*bottle[i+1] points.
The more points you score, the more rewards you can win.

Your task is to score the maximum points by shooting all the ballons wisely.

Note: After you shoot bottle at i-th index, bottles at i-1 and i+1 positions
become adjacent. if there is no existing 'i-1' or 'i+1' positions for selected bottle.
you can assume that bottle[i-1] = bottle[i+1] = 1.

Input Format:
-------------
N space separated integers bottles[]you.

Output Format:
--------------
Print an integer, maximum points you can get.


Sample Input:
---------------
3 1 5 8

Sample Output:
----------------
167

Explanation:
------------
Given bottles = [3, 1, 5, 8] 
position 	points
--------------------
1				3*1*5
5				3*5*8
3				1*3*8
8				1*8*1
--------------------
Total = 167


Sample Input:
---------------
2 1 3 5 4

Sample Output:
----------------
102

Explanation:
------------
Given bottles = [2, 1, 3, 5, 4] 

position 	points
--------------------
5				3*5*4
1				2*1*3
3				2*3*4
2				1*2*4
4				1*4*1
--------------------
Total = 102

*/

import java.util.*;

public class BurstBalloons {
    static int dp[][];

    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        String s = ip.nextLine();
        int inputArray[] = Arrays.stream(s.split(" ")).mapToInt(Integer::valueOf).toArray();
        int n = inputArray.length;
        int arr[] = new int[n + 2];
        arr[0] = arr[n + 1] = 1;
        for (int i = 0; i < n; i++)
            arr[i + 1] = inputArray[i];

        dp = new int[n + 2][n + 2];
        for (int i = 0; i <= n; i++)
            Arrays.fill(dp[i], -1);
        int res = recurr(arr, 0, n + 1);
        System.out.println(res);
    }

    public static int recurr(int[] arr, int left, int right) {
        if (left > right)
            return 0;
        if (left < 0 || right < 0)
            return 1;

        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = 0;
        for (int i = left + 1; i < right; i++) {
            int fromLeft = recurr(arr, left, i);
            int fromRight = recurr(arr, i, right);
            int currAns = arr[left] * arr[i] * arr[right];
            ans = Math.max(ans, fromLeft + fromRight + currAns);
        }
        return dp[left][right] = ans;
    }
}