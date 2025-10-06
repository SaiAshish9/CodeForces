import java.util.Scanner;
import java.io.PrintWriter;
 
public class Main {
 
    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
 
        int t = scanner.nextInt(); 
        
        while (t-- > 0) {
            int n = scanner.nextInt(); 
            int k = scanner.nextInt(); 
            String s = scanner.next(); 
 
            int L = 1; 
            int R = n; 
            int c2 = 0; 
 
            for (int i = 0; i < k; i++) {
                char action = s.charAt(i);
                
                if (action == '0') {
                    L++;
                } else if (action == '1') {
                    R--;
                } else {
                    c2++;
                }
            }
 
            StringBuilder result = new StringBuilder(n);
            
            boolean all_core_removed = (R - L + 1 <= c2);
 
            for (int i = 1; i <= n; i++) {
                if (i < L || i > R) {
                    result.append('-');
                } else {
                    if (all_core_removed) {
                        result.append('-');
                    } else if (i < L + c2 || i > R - c2) {
                        result.append('?');
                    } else {
                        result.append('+');
                    }
                }
            }
            
            out.println(result.toString());
        }
 
        out.flush();
        scanner.close();
        out.close();
    }
 
    public static void main(String[] args) {
        solve();
    }
}