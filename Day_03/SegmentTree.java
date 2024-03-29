/*

Malika taught a new fun time program practice for Engineering Students.
As a part of this she has given set of numbers, and asked the students 
to find the minimum number between indices S1 and S2 (S1<=S2), inclusive.

Now it’s your task to implement the Solution class:

	segmentTree(int[] nums, int n): 
	-------------------------------
	    - build the Segment tree with the integer array nums[].
	    - n is size of the array.
	    
	int findMinimum(int n, int S1, int S2):
	---------------------------------------
	    - n is size of the array.
	    - S1, S2 are indices
	    
	Returns the minimum value in the subarray nums[S1, S2] 
	(i.e., nums[S1] + nums[S1 + 1], ..., nums[S2] ).


Input Format:
-------------
Line-1: An integer n, size of the array nums[] (set of numbers).
		where 1<= n <= 50000
Line-2: Two integers S1 and S2, index positions 
		where 0 <= S1 <= S2 < n
		and 1<= nums[i] <= 99999.

Output Format:
--------------
An integer, sum of integers between indices(s1, s2).


Sample Input-1:
---------------
10
2 9

Sample Output-1:
----------------
10208

NOTE: First 10 values of the input are: 
66905 11444 18252 54299 10208 59466 17861 24128 31974 69081

*/

import java.util.*;

class SegmentTree
{ 
    static int INF = (int)(1e7 + 9);
    static int n;
    static int t[];
    
    // method to implement segment tree
	void segmentTree(int nums[], int n) 
	{ 
	    this.n = n;
	    t = new int[4*n];
        build(nums, 1, 0, n-1);
	} 

    // method to find the minimum value in the range 
	int findMinimum(int n, int s1, int s2) 
	{ 
	   // mini = INF;
        int mini = findMini(1, 0, n-1, s1, s2);
        return mini;
	} 
	
	private static int findMini(int v, int tl, int tr, int l, int r)
	{
	    if(l > r) {
	        return INF;
	    }
	
	    if(l == tl && r == tr) {
	        return t[v];
	    }
	    int mid = (tl + tr)/2;
	    int x = r<mid?r:mid;
	    int y = ((mid+1)>l)?mid+1:l;
	    
	    int p = findMini(v*2, tl, mid, l, x);
	    int q = findMini(v*2 + 1, mid+1, tr, y, r);
	    return (p<q)?p:q;

	}
	
	
	
	
	private static void build(int nums[], int v, int tl, int tr)
	{
	    if(tl == tr) {
	        t[v] = nums[tl];
	        return;
	    }
	    int mid = tl + (tr-tl)/2;
	    build(nums, 2*v, tl, mid);
	    build(nums, 2*v+1, mid+1, tr);
	    t[v] = (t[v*2]<t[v*2 + 1])?t[v*2]:t[v*2+1];
	}
}
