import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.io.PrintWriter;
import java.lang.Math;
 
public class Main {
 
    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
 
        int t = scanner.nextInt(); 
        
        while (t-- > 0) {
            int n = scanner.nextInt(); 
            String s = scanner.next(); 
 
            int[] balance = new int[n + 1];
            for (int i = 0; i < n; i++) {
                int value = (s.charAt(i) == 'a') ? 1 : -1;
                balance[i + 1] = balance[i] + value;
            }
 
            int total_diff = balance[n];
 
            if (total_diff == 0) {
                out.println(0);
                continue;
            }
            
            Map<Integer, Integer> last_occurrence = new HashMap<>();
            
            last_occurrence.put(0, 0); 
            
            int min_k = n; 
 
            for (int j = 1; j <= n; j++) {
                int start_balance_target = balance[j] - total_diff;
 
                if (last_occurrence.containsKey(start_balance_target)) {
                    int i_last = last_occurrence.get(start_balance_target);
 
                    int k = j - i_last;
                    
                    if ((n - k) % 2 == 0) {
                         min_k = Math.min(min_k, k);
                    }
                }
                
                last_occurrence.put(balance[j], j);
            }
            
            if (min_k == n) {
                out.println(-1);
            } else {
                out.println(min_k);
            }
        }
 
        out.flush();
        scanner.close();
        out.close();
    }
 
    public static void main(String[] args) {
        solve();
    }
}