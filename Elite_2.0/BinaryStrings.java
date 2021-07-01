/*
Mounika is creating the binary strings using P 1's and Q 0's.
A binary string contains only 0's and 1's.
She has given a list of binary strings binStr[] to be formed.

Her task is to find, the maximum number of binary strings can be formed, 
with given P 1's and Q 0's only. She cannot use any more 1's or 0's.

Input Format:
-------------
Line-1 -> A single line of space separated binary strings, binStr[].
Line-2 -> Two integers P and Q, P number of 1's and Q number of 0's


Output Format:
--------------
Print an integer as output, maximum number of binary strings can be formed.


Sample Input-1:
---------------
10 0001 111001 1 0
3 5

Sample Output-1:
----------------
4

Explanation:
------------
She can form 4 strings by the using of 3 1's and 5 0's
strings are 10, 0001, 1, 0.


Sample Input-2:
---------------
10 1 0
1 1

Sample Output-2:
----------------
2

Explanation:
------------
She can form 2 strings by the using of 1 1's and 1 0's
strings are 1, 0.


*/

import java.util.*;

public class BinaryStrings {
    static HashMap<String, Integer> map;

    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        map = new HashMap<>();
        String[] binStrs = ip.nextLine().split(" ");
        int p = ip.nextInt();
        int q = ip.nextInt();
        int n = binStrs.length;

        int ans = knapSack(binStrs, p, q, n);
        System.out.println(ans);
        ip.close();
    }

    private static int knapSack(String[] args, int p, int q, int n) {
        if (n == 0)
            return 0;

        if (p == 0 && q == 0)
            return 0;
        String key = n + "#" + p + "#" + q;
        if (map.containsKey(key)) {
            return map.get(key);
        }
        int zeros = 0, ones = 0;
        for (char ch : args[n - 1].toCharArray()) {
            if (ch == '0')
                zeros++;
            else
                ones++;
        }

        if (ones <= p && zeros <= q) {
            int best = Math.max(1 + knapSack(args, p - ones, q - zeros, n - 1), knapSack(args, p, q, n - 1));
            map.put(key, best);
            return best;
        }
        int ans = knapSack(args, p, q, n - 1);
        map.put(key, ans);
        return ans;
    }
}