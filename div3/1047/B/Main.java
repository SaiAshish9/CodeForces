import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int[] p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = scanner.nextInt();
            }

            int[] q = new int[n];
            for (int i = 0; i < n; i++) {
                q[i] = n + 1 - p[i];
            }

            for (int i = 0; i < n; i++) {
                System.out.print(q[i] + " ");
            }
            System.out.println();
        }

        scanner.close();
    }
}