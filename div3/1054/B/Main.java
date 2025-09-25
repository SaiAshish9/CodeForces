import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        
        while (t-- > 0) {
            int n = scanner.nextInt();
            long[] arr = new long[n];
            
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextLong();
            }
            
            Arrays.sort(arr);
            
            long maxDiff = 0;
            
            for (int i = 0; i < n; i += 2) {
                long diff = Math.abs(arr[i + 1] - arr[i]);
                if (diff > maxDiff) {
                    maxDiff = diff;
                }
            }
            
            System.out.println(maxDiff);
        }
        
        scanner.close();
    }
}
