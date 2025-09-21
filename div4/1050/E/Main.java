import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] a = new int[n];
            int[] freq = new int[n + 1];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                freq[a[i]]++;
            }
 
            // Check if any value has freq not divisible by k
            boolean possible = true;
            for (int i = 1; i <= n; i++) {
                if (freq[i] % k != 0) {
                    possible = false;
                    break;
                }
            }
            if (!possible) {
                System.out.println(0);
                continue;
            }
 
            // Precompute the limit for each value
            int[] limit = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                limit[i] = freq[i] / k;
            }
 
            int l = 0;
            int[] currentFreq = new int[n + 1];
            long ans = 0;
            for (int r = 0; r < n; r++) {
                currentFreq[a[r]]++;
                while (currentFreq[a[r]] > limit[a[r]]) {
                    currentFreq[a[l]]--;
                    l++;
                }
                ans += (r - l + 1);
            }
            System.out.println(ans);
        }
    }
}