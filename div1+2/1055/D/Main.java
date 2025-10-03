import java.util.Scanner;

public class Main {

    static final int MAX_SIZE = 1_000_010;
    static int[] prefixStepsPlusOne = new int[MAX_SIZE];
    static int[] prefixDifferentSteps = new int[MAX_SIZE];
    static int[] numbers = new int[MAX_SIZE];

    static int calculateSteps(int value) {
        value /= 2;
        int steps = 1;
        while (value > 1) {
            value = (value + 1) / 2;
            steps++;
        }
        return steps;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();

        while (testCases-- > 0) {
            int arraySize = scanner.nextInt();
            int queryCount = scanner.nextInt();

            // Reset prefix arrays for each test case
            prefixStepsPlusOne[0] = 0;
            prefixDifferentSteps[0] = 0;

            for (int i = 1; i <= arraySize; i++) {
                numbers[i] = scanner.nextInt();

                int stepsOriginal = calculateSteps(numbers[i]);
                int stepsPlusOne = calculateSteps(numbers[i] + 1);

                prefixStepsPlusOne[i] = prefixStepsPlusOne[i - 1] + stepsPlusOne;
                prefixDifferentSteps[i] = prefixDifferentSteps[i - 1] + (stepsOriginal != stepsPlusOne ? 1 : 0);
            }

            for (int q = 0; q < queryCount; q++) {
                int left = scanner.nextInt();
                int right = scanner.nextInt();

                int totalStepsInRange = prefixStepsPlusOne[right] - prefixStepsPlusOne[left - 1];
                int differencesInRange = prefixDifferentSteps[right] - prefixDifferentSteps[left - 1];

                int result = totalStepsInRange - (differencesInRange + 1) / 2;
                System.out.println(result);
            }
        }

        scanner.close();
    }
}
