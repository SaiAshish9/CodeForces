import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCount = scanner.nextInt();
 
        while (testCount-- > 0) {
            int n = scanner.nextInt();
            long[] values = new long[n];
 
            for (int i = 0; i < n; i++) {
                values[i] = scanner.nextLong();
            }
 
            long initialAltSum = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    initialAltSum += values[i];
                } else {
                    initialAltSum -= values[i];
                }
            }
 
            long maxResult = initialAltSum;
 
            // Try improving the result by the logic from the original C++ code:
            // Increasing by i - (i % 2)
            for (int i = 0; i < n; i++) {
                long candidate = initialAltSum + i - (i % 2);
                if (candidate > maxResult) {
                    maxResult = candidate;
                }
            }
 
            long minEven = Long.MAX_VALUE / 2;
            long minOdd = Long.MAX_VALUE / 2;
 
            for (int i = 0; i < n; i++) {
                if (i % 2 == 1) {
                    maxResult = Math.max(maxResult, initialAltSum + i + 2 * values[i] - minEven);
                    minOdd = Math.min(minOdd, i - 2 * values[i]);
                } else {
                    maxResult = Math.max(maxResult, initialAltSum + i - 2 * values[i] - minOdd);
                    minEven = Math.min(minEven, i + 2 * values[i]);
                }
            }
 
            System.out.println(maxResult);
        }
        scanner.close();
    }
}
