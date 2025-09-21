import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();

        while (testCases-- > 0) {
            int arraySize = scanner.nextInt();
            int multiplierLimit = scanner.nextInt();

            Integer[] numbers = new Integer[arraySize];
            for (int i = 0; i < arraySize; i++) {
                numbers[i] = scanner.nextInt();
            }

            Arrays.sort(numbers, Collections.reverseOrder());

            long totalSum = 0;
            int elementsToConsider = Math.min(arraySize, multiplierLimit);

            for (int i = 0; i < elementsToConsider; i++) {
                totalSum += (long) numbers[i] * (multiplierLimit - i);
            }

            System.out.println(totalSum);
        }

        scanner.close();
    }
}
