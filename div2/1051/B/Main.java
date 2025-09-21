import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(), k = sc.nextInt();
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
                a[i] = sc.nextInt();
            Integer[] b = new Integer[k];
            for (int i = 0; i < k; i++)
                b[i] = sc.nextInt();

            // Sort prices descending
            Arrays.sort(a, Collections.reverseOrder());
            // Sort vouchers ascending
            Arrays.sort(b);

            long total = 0;
            int idx = 0;

            for (int i = 0; i < k; i++) {
                int size = b[i];
                // pay for first (size - 1) items in this group
                for (int j = 0; j < size - 1 && idx < n; j++) {
                    total += a[idx++];
                }
                // skip the free one
                if (idx < n)
                    idx++;
            }

            // remaining items (if any)
            while (idx < n) {
                total += a[idx++];
            }

            System.out.println(total);
        }
        sc.close();
    }
}
