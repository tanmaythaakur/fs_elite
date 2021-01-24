/*
Vihaan is given a pair of words likely word1 and word2, 
he is asked to create a method which returns the numbers of characters in a word 
formed from long lasting frequent posteriority.

Posteriority is the word formed from the original word with few characters removed
without modifying the corresponding order of the left over characters.

Find the longest common posteriority of two words.
Return 0 if no common posteriority.

Input Format:
-------------
Two space separated strings S1, S2.

Output Format:
--------------
Print an integer, the length of longest common prosperity.


Sample Input-1:
---------------
abcde ace

Sample Output-1:
----------------
3


Sample Input-2:
---------------
acd bef

Sample Output-2:
----------------
0

*/

import java.util.*;

public class FindLCS {
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        
        String s1 = new String();
        String s2 = new String();
        s1 = ip.next();
        s2 = ip.next();
        
        System.out.println(LCS(s1, s2));
    }
    
    static int LCS(String s1, String s2)
    {
        int m = s1.length();
        int n = s2.length();
        int dp[][] = new int[m+1][n+1];
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1.charAt(i-1) == s2.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
}