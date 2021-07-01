/*
Gumadi Baleshwar Rao purchased two boxes (Box1,Box2) of unique weights 
of gold coins, where first box weights are subset of second box gold weights.

Now design a method for Gumadi Baleshwar Rao to find all the next largest weights 
of Box1 gold coins in the corresponding locations of box2 , 
if doesn’t exist return -1.

The Next largest Weight is Weight ‘W’ in Box1 is the first largest weight 
to its right side weight in Box2.

NOTE: Unique weights means, no two coins will have same weight.

Input Format:
-------------
Line-1: space separated integers, weihts of gold coins in the first box.
Line-2: space separated integers, weihts of gold coins in the second box.

Output Format:
--------------
Print a list of integers, next largest weights

Sample Input-1:
---------------
4 3 2
1 3 4 2

Sample Output-1:
----------------
[-1, 4, -1]


Sample Input-2:
---------------
5 6 3 4
1 5 3 7 8 6 4 2

Sample Output-2:
----------------
[7, -1, 7, -1]


*/

import java.util.*;

public class NextGrtst {
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        String line = new String(ip.nextLine());
        int arr1[] = Arrays.stream(line.split(" ")).mapToInt(Integer::valueOf).toArray();
        line = ip.nextLine();
        int arr2[] = Arrays.stream(line.split(" ")).mapToInt(Integer::valueOf).toArray();

        Stack<Integer> st = new Stack<Integer>();
        int n = arr2.length;

        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 && st.peek() <= arr2[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                mp.put(arr2[i], -1);
            } else {
                mp.put(arr2[i], st.peek());
            }
            st.push(arr2[i]);
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int x : arr1) {
            ans.add(mp.get(x));
        }
        System.out.println(ans);
    }
}