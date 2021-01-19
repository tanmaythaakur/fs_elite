/*
There are pair of words namely W1 and W2 with a limited of word range, 
Create a method to return a true value if W2 contains the anagram of W1. 
In additional, one of the anagram of first word is the substring of the second word.

Your task is to implement the Solution class, and implement a method in it, 
	- public boolean checkSubstring(String w1, String w2){}.

Input Format:
-------------
Two space separated words w1 and w2, consist of lowercase letters only.

Output Format:
--------------
Print a boolean value, if W2 contains the anagram of W1 or not.


Sample Input-1:
---------------
abbcbb abbbabbcb

Sample Output-1:
----------------
true


Sample Input-2:
---------------
abbcbbc abbbabbcb

Sample Output-2:
----------------
false

*/



public class AnagramCheck {
    
    private static int patArr[] = new int[26];
    private static int strArr[] = new int[26];
    
    private static boolean checkAnagram()
    {
        for(int i=0; i<26; i++) {
            if(patArr[i] != strArr[i])
                return false;
        }
        return true;
    }
    
    
    private static long telHash(String pat){
        int n = pat.length();
        long ans = 0;
        
        for(int i=0; i<n; i++) {
            ans += pat.charAt(i) - 'a' + 1;
        }
        
        return ans;
    }
    
    public boolean checkSubstring(String pat, String str){
        
        int n = pat.length();
        int m = str.length();
        
        if(n > m) return false;
        
        int idx = 0;
        for(; idx<n; idx++) {
            patArr[pat.charAt(idx) - 'a']++;
        }
        
        long hashP = telHash(pat);
        long hashS = telHash(str.substring(0, n));
        
        
        idx = 0;
        for(; idx<n; idx++) {
            strArr[str.charAt(idx) - 'a']++;    
        }
        
        for(; idx < m; idx++) {
            // System.out.println(hashS + " " + hashP);
            if(hashS == hashP && checkAnagram()) {
                return true;
            }
            strArr[str.charAt(idx) - 'a']++;
            strArr[str.charAt(idx - n) - 'a']--;
            
            hashS -= (str.charAt(idx-n) - 'a');
            hashS += (str.charAt(idx) - 'a');
        }
        if(hashS == hashP && checkAnagram()) return true;
        
        return false;
    
    }
}