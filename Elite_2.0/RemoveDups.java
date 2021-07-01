import java.util.*;

public class RemoveDups {
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        String str = ip.next();

        int n = str.length();

        HashMap<Character, Integer> last = new HashMap<>();
        Stack<Character> st = new Stack<>();
        boolean[] taken = new boolean[26];

        for (int i = n - 1; i >= 0; i--) {
            if (!last.containsKey(str.charAt(i))) {
                last.put(str.charAt(i), i);
            }
        }

        /*
         * for (int i = 0; i < n; i++) { int idx = str[i] - 'a'; char ch = str[i];
         * 
         * if (taken[idx]) continue;
         * 
         * while (!st.empty() && (st.top() > ch) && (last[st.top()] > i)) {
         * taken[st.top()] = false; st.pop(); } st.push(ch); taken[idx] = true; }
         */

        for (int i = 0; i < n; i++) {
            int idx = str.charAt(i) - 'a';
            char ch = str.charAt(i);
            if (taken[idx])
                continue;

            while (!st.isEmpty() && (st.peek() > ch) && last.get(st.peek()) > i) {
                taken[st.peek() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            taken[idx] = true;

        }

        while (!st.isEmpty()) {
            System.out.print(st.pop());
        }

        ip.close();
    }
}