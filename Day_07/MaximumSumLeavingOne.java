/*
Vijay is playing with set of boxes, each box is printed a number on it.
all the boxes placed in a row.

You are given the numbers printed on the boxes in the row.
Your task is to find the maximum sum of the numbers when one box is removed 
from the sub-set of boxes, and the sub-set is selected as a contiguous set of 
boxes from the row. 

Note: The sub-set should not be empty after removal of a box.

Input Format:
-------------
Single line of space separated integers, number on the boxes.

Output Format:
--------------
Print an integer, Maximum sum of sub-set of boxes,
after removal of a box.


Sample Input-1:
---------------
-2 -3 4 -1 -2 1 5 -3

Sample Output-1:
----------------
9

Sample Input-2:
---------------
-2 -3 -4 -1 -2 1 5 -3 8

Sample Output-2:
----------------
14



*/

import java.util.*;

public class MaximumSumLeavingOne {
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        String line = new String(ip.nextLine());

        int arr[] = Arrays.stream(line.split(" ")).mapToInt(Integer::valueOf).toArray();

        int n = arr.length;
        int dp[][] = new int[2][n];

        dp[0][0] = arr[0];
        int ans = -99999999;
        for (int i = 1; i < n; i++) {
            dp[0][i] = Math.max(dp[0][i - 1] + arr[i], arr[i]);
            dp[1][i] = Math.max(dp[0][i - 1], dp[1][i - 1] + arr[i]);
            ans = Math.max(ans, Math.max(dp[1][i], dp[0][i]));
        }
        System.out.println(ans);
    }
}