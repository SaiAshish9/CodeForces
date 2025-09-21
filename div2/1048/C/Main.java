import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int k = scanner.nextInt();
            long x = scanner.nextLong();
            long total = 1L << (k + 1); // 2^(k+1)
            long half = total / 2; // 2^k
            List<Integer> steps = new ArrayList<>();
            long current = x;
            while (current != half) {
                if (current <= half) {
                    steps.add(1);
                    current *= 2;
                } else {
                    steps.add(2);
                    current = 2 * current - total;
                }
            }
            Collections.reverse(steps);
            System.out.println(steps.size());
            if (!steps.isEmpty()) {
                for (int op : steps) {
                    System.out.print(op + " ");
                }
                System.out.println();
            }
        }
        scanner.close();
    }
}
