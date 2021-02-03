import java.util.*;

public class BuyAndSellDiamonds {
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        String line = new String(ip.nextLine());

        int arr[] = Arrays.stream(line.split(" ")).mapToInt(Integer::valueOf).toArray();
        int n = arr.length;

        int rest[] = new int[n];
        int hold[] = new int[n];
        int sold[] = new int[n];

        hold[0] = -arr[0];

        for (int i = 1; i < n; i++) {
            rest[i] = Math.max(rest[i - 1], sold[i - 1]);
            hold[i] = Math.max(hold[i - 1], rest[i - 1] - arr[i]);
            sold[i] = hold[i - 1] + arr[i];
        }

        int ans = Math.max(rest[n - 1], sold[n - 1]);
        System.out.println(ans);
    }
}