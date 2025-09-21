import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            long[] a = new long[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
                a[i] += (a[i] % (k + 1)) * k;
            }

            for (long num : a) {
                System.out.print(num + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
