import java.util.*;



// N^2 solution. Working on optimization
public class LargestMul {
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        String []words = ip.nextLine().split(" ");
        int n = words.length;

        int [][]count = new int[n][26];

        for(int i = 0; i < n; i++) {
            for(char ch: words[i].toCharArray()) {
                count[i][ch-'a']++;
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                boolean flag = false;
                for(int k=0; k<26; k++) {
                    if(count[i][k] > 0 && count[j][k] > 0) {
                        flag = true;
                        break;
                    }
                }
                if(!flag) {
                    ans = Math.max(ans, words[i].length() * words[j].length());
                }
            }
        }


        System.out.println(ans);

    }
}