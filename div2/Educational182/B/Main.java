import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
 
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
 
            int[] prefixSum = new int[n + 1];
            for (int i = 0; i < n; i++) {
                prefixSum[i + 1] = prefixSum[i] + arr[i];
            }
 
            boolean found = false;
            int lResult = 0, rResult = 0;
 
            for (int l = 1; l < n - 1 && !found; l++) {
                for (int r = l + 1; r < n && !found; r++) {
                    int s1 = (prefixSum[l] - prefixSum[0]) % 3;
                    int s2 = (prefixSum[r] - prefixSum[l]) % 3;
                    int s3 = (prefixSum[n] - prefixSum[r]) % 3;
 
                    if (allEqual(s1, s2, s3) || allDifferent(s1, s2, s3)) {
                        lResult = l;
                        rResult = r;
                        found = true;
                    }
                }
            }
 
            if (found) {
                System.out.println(lResult + " " + rResult);
            } else {
                System.out.println("0 0");
            }
        }
 
        sc.close();
    }
 
    private static boolean allEqual(int a, int b, int c) {
        return a == b && b == c;
    }
 
    private static boolean allDifferent(int a, int b, int c) {
        return a != b && b != c && a != c;
    }
}