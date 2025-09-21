
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while (t-- > 0) {
            long a = scanner.nextLong();
            long b = scanner.nextLong();

            long candidate1 = a + b;
            long candidate2 = a * b + 1;
            long maxEven = -1;

            if (candidate1 % 2 == 0) {
                maxEven = Math.max(maxEven, candidate1);
            }
            if (candidate2 % 2 == 0) {
                maxEven = Math.max(maxEven, candidate2);
            }

            if (b % 2 == 0) {
                long candidate3 = 2 * a + b / 2;
                long candidate4 = a * (b / 2) + 2;
                if (candidate3 % 2 == 0) {
                    maxEven = Math.max(maxEven, candidate3);
                }
                if (candidate4 % 2 == 0) {
                    maxEven = Math.max(maxEven, candidate4);
                }
            }

            System.out.println(maxEven);
        }

        scanner.close();
    }
}
