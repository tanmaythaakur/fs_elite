import java.util.*;

class Coupons {
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        int n = ip.nextInt();
        int []cps = new int[n];
        int []exps = new int[n];
        
        for(int i=0; i<n; i++)
            cps[i] = ip.nextInt();
        
        for(int i=0; i<n; i++) 
            exps[i] = ip.nextInt();
            
        int res = 0;
        int i = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> (a + days[a] - b + days[b]));
        
        for(; i<cps.length; i++) {
            if(cps[i] != 0)
                pq.offer(i);
            
            while(!pq.isEmpty() && pq.peek() + days[pq.peek()] <= i)
                pq.poll();
            
            if(pq.isEmpty())
                continue;
            
            cps[pq.peek()]--;
            res++;
            if(cps[pq.peek()] == 0)
                pq.poll();
        }
        
        while(!pq.isEmpty()) {
            while(!pq.isEmpty() && pq.peek() + days[pq.peek()] <= i)
                pq.poll();
            
            if(pq.isEmpty())
                continue;
            res++;
            if(cps[pq.peek()] == 0)
                pq.poll();
            i++;
        }
        System.out.println(res);
    }
}