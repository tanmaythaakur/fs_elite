/*
M.P.Ahammed the founder of Malbar Gold and Diamonds merchant, announced an offer
that they will charge the minimum amount to make all the gold-biscuits into one.

Sharvan a gold supplier has different weighed gold-biscuits with him.
He wants to utilize the offer.

The processing charge to make two biscuits into one is calculated as follows:
	- To make two biscuits of weights A and B into one biscuit, 
	you have to pay the amount 'A + B'. 

Your task is to help M.P.Ahammed to keep his promise and 
to charge the minimum amount to make Mr. Shravan's gold-biscuits 
into one gold-biscuit.

Input Format:
-------------
Single line of space separated integers, number on the boxes.

Output Format:
--------------
Print an integer, minimum amount to be paid by Mr Shravan.



Sample Input-1:
---------------
4 3 6

Sample Output-1:
----------------
45


Sample Input-2:
---------------
5 2 4 3 6

Sample Output-2:
----------------
45


*/


import java.util.*;

public class MergeBiscuits {
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        String line = new String(ip.nextLine());

        int arr[] = Arrays.stream(line.split(" ")).mapToInt(Integer::valueOf).toArray();

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int x : arr) {
            pq.offer(x);
        }

        int ans = 0;

        while (pq.size() != 1) {
            int x = pq.poll();
            int y = pq.poll();
            ans += (x + y);
            pq.offer(x + y);
        }
        System.out.println(ans);

    }
}