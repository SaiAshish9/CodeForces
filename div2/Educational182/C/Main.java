import java.util.*;
 
public class Main {
    static final long MOD = 998244353;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
 
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n + 1];
            int[] b = new int[n + 1];
            for (int i = 1; i <= n; i++) a[i] = sc.nextInt();
            for (int i = 1; i <= n; i++) b[i] = sc.nextInt();
 
            long[][] dp = new long[n + 1][2];
            dp[1][0] = 1; // no swap at position 1
            dp[1][1] = 1; // swap at position 1
 
            for (int i = 2; i <= n; i++) {
                // case previous not swapped
                if (a[i - 1] <= a[i] && b[i - 1] <= b[i]) {
                    dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
                }
                if (a[i - 1] <= b[i] && b[i - 1] <= a[i]) {
                    dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
                }
 
                // case previous swapped
                if (b[i - 1] <= a[i] && a[i - 1] <= b[i]) {
                    dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
                }
                if (b[i - 1] <= b[i] && a[i - 1] <= a[i]) {
                    dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
                }
            }
 
            long ans = (dp[n][0] + dp[n][1]) % MOD;
            System.out.println(ans);
        }
    }
}