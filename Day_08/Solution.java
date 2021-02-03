/*
 * In South Central Railways, There are N Railway Tracks, Each Railway track
 * passing through a set of stations, each station indicated with positive
 * integer.
 * 
 * You are given K railway-tracks information, with the stations number list of
 * each track in ascending order.
 * 
 * Your task is to return the merged list of station numbers of all tracks
 * together
 * 
 * 
 * NOTE: Your task is to implement mergeKTracks() given in Solution Class.
 * 
 * Method Signature: ----------------- public ListNode mergeKTracks(ListNode[]
 * tracks)
 * 
 * Input Format: ------------- Line-1: AN integer K, number of railway tracks
 * Next K lines: space separated of integrs, numbers of stations in each track.
 * 
 * Output Format: -------------- Print the list of merged station numbers of all
 * tracks.
 * 
 * 
 * Sample Input-1: --------------- 3 1 2 3 4 2 4 8 2 3 7 11
 * 
 * Sample Output-1: ---------------- 1 2 2 2 3 3 4 4 7 8 11
 * 
 * 
 * 
 * Sample Input-2: --------------- 3 1 3 8 10 2 5 8 9 3 5 6 8 10
 * 
 * Sample Output-2: ---------------- 1 2 3 3 5 5 6 8 8 8 9 10 10
 * 
 * 
 */

/*
Singly Linked List
class ListNode{
  // Members of the class are:
  int val;    // station number
  ListNode next;  // next station
}

*/

/*
Singly Linked List
class ListNode{
    // Members of the class are:
    int val;    // station number
    ListNode next;  // next station
}

*/
import java.util.*;

class Solution {
    // Implement mergeKLists method
    public ListNode mergeKTracks(ListNode[] tracks) {
        int n = tracks.length;
        ListNode head = new ListNode();
        ListNode trav = head;

        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> (a.val - b.val));

        for (int i = 0; i < n; i++) {
            pq.offer(tracks[i]);
        }

        while (pq.size() > 0) {
            ListNode top = pq.poll();
            trav.next = new ListNode();
            trav = trav.next;
            trav.val = top.val;

            if (top.next != null) {
                pq.offer(top.next);
            }
        }

        return head.next;
    }
}
