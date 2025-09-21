import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] p = new int[n];
            for (int i = 0; i < n; ++i)
                p[i] = sc.nextInt();
            int l = 0, r = n - 1;
            boolean ok = true;
            for (int k = 1; k <= n; ++k) {
                if (p[l] == k) {
                    l++;
                } else if (p[r] == k) {
                    r--;
                } else {
                    ok = false;
                    break;
                }
            }
            System.out.println(ok ? "YES" : "NO");
        }
        sc.close();
    }
}
