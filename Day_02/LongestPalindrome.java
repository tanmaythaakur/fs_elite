/*
Mr. James professor of at Illinois state university, as a part of assignment he created a
problem statement related to strings.
He gave a String S, and asked them to design a method to 
return the longest substring in S, which is a palindrome.

NOTE: Alphabets are case sensitive
"Aa" is not considered a palindrome here.

Input Format:
-------------
A string S, consist of lowercase/uppercase letters or/and digits

Output Format:
--------------
Print a string, longest palindrome substring.


Sample Input-1:
---------------
abbbabbcbbacdb

Sample Output-1:
----------------
abbcbba


Sample Input-2:
---------------
thedivideriswide

Sample Output-2:
----------------
edivide

*/

import java.util.*;

public class LongestPalindrome {
    
    public static void main(String []args) {
        Scanner ip = new Scanner(System.in);
        String str = new String(ip.next());
        StringBuilder sb = new StringBuilder(str);
        sb.reverse();
        String ans = new String();
        ans = longestPalin(str, sb.toString());
        System.out.println(ans);
        
    }
    
    private static String longestPalin(String s1, String s2)
    {
        int n = s2.length();
        
        int dp[][] = new int[n+1][n+1];
        
        int maxi = 0;
        int sti = -1, stj = -1;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s1.charAt(i-1) == s2.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 0;
                }
                if(maxi < dp[i][j]) {
                    maxi = dp[i][j];
                    sti = i;
                    stj = j;
                }
            }
        }
        
        
        StringBuilder sb = new StringBuilder();
        
        while(sti > 0 && stj > 0) {
            if(dp[sti][stj] == 0) 
                break;
            
            sb.append(s1.charAt(sti-1));
            sti--;
            stj--;
        }
        String ans = new String(sb.toString());
        return ans;
        
        
    }
    
    
}