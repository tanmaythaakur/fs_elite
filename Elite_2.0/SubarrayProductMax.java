/*
Ashok is given an array of integers nums.
His task is to find the longest contiguous subsequence S, 
the product of all the numbers in the subsequence should be positive.

Return the length of longest contiguous subarray.

Input Format:
-------------
Space separated integers nums[], list of numbers.

Output Format:
--------------
Print the length of the longest contiguous subsequence


Sample Input-1:
---------------
1 -1 2 -2

Sample Output-1:
----------------
4


Sample Input-2:
---------------
-1 -2 -3 0 1

Sample Output-2:
----------------
2

Explanation:
------------
0 is considered as positive number.


Sample Input-3:
---------------
1 2 3 4 -5 6  7 8

Sample Output-3:
----------------
4

*/

import java.util.*;

public class SubarrayProductMax {

    private static int findProd(ArrayList<Integer> arr) {
        int firstNeg = -1, lastNeg = -1;
        boolean evenNegs = true;
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i) < 0) {
                if (firstNeg == -1)
                    firstNeg = i;
                lastNeg = i;
                evenNegs = !evenNegs;
            }
        }

        // no negatives found or even number of negs found
        if (evenNegs) {
            // System.out.println(arr.length);
            ans = arr.size();
        } else {
            ans = Math.max(arr.size() - firstNeg - 1, lastNeg);
            // System.out.println(ans);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        String s = ip.nextLine();
        int arr[] = Arrays.stream(s.split(" ")).mapToInt(Integer::valueOf).toArray();
        int ans = 0;

        ArrayList<Integer> arrl = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                ans = Math.max(findProd(arrl), ans);
                arrl.clear();
            } else {
                arrl.add(arr[i]);
            }
        }
        ans = Math.max(findProd(arrl), ans);
        System.out.println(ans);
    }
}

/*
 * import java.util.*;
 * 
 * public class Main { public static void main(String[] args) { Scanner ip = new
 * Scanner(System.in); String s = ip.nextLine(); int arr[] =
 * Arrays.stream(s.split(" ")).mapToInt(Integer::valueOf).toArray();
 * 
 * int pos = 0, neg = 0; int ans = 0;
 * 
 * for (int i = 0; i < arr.length; i++) { if (arr[i] == 0) { pos = 0; neg = 0; }
 * else if (arr[i] > 0) { pos++; if (neg > 0) neg++; } else { int temp = neg;
 * neg = pos; pos = temp;
 * 
 * neg++; if (pos > 0) pos++; } ans = Math.max(pos, ans); }
 * 
 * System.out.println(ans); } }
 */