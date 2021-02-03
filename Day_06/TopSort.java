import java.util.*;

public class TopSort {

    static ArrayList<Integer> graph[];
    static boolean vis[];
    static int inDeg[];
    static ArrayList<Integer> ans = new ArrayList<>();

    static void dfs(int src) {
        vis[src] = true;

        for (int x : graph[src]) {
            if (!vis[x]) {
                dfs(x);
            }
        }
        ans.add(src);
    }

    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        int n = ip.nextInt();
        int m = ip.nextInt();

        graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        vis = new boolean[n];

        int x, y;
        inDeg = new int[n];
        for (int i = 0; i < m; i++) {
            x = ip.nextInt();
            y = ip.nextInt();
            graph[x].add(y);
            inDeg[y]++;
        }

        boolean flag = false;
        for (int t : inDeg) {
            if (t == 0) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            System.out.println(ans);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        System.out.println(ans);
    }
}