import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] arr = new int[n];
            boolean[] present = new boolean[k];
            int countK = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                if (arr[i] == k) countK++;
                if (arr[i] < k) present[arr[i]] = true;
            }
            int missingCount = 0;
            for (boolean b : present) {
                if (!b) missingCount++;
            }
            System.out.println(Math.max(missingCount, countK));
        }
    }
}