import java.util.*;

public class Main {

    public static void solve(Scanner scanner) {
        int rangeStart = scanner.nextInt();
        int rangeEnd = scanner.nextInt();

        long bitMask = 1;
        long totalSum = 0;

        while (bitMask < rangeEnd) {
            bitMask = (bitMask << 1) | 1;
        }

        Set<Integer> availableNumbers = new HashSet<>();
        for (int number = rangeStart; number <= rangeEnd; number++) {
            availableNumbers.add(number);
        }

        int[] assignedValues = new int[rangeEnd + 1];

        for (int current = rangeEnd; current >= rangeStart; current--) {
            while (!availableNumbers.contains((int)(bitMask - current))) {
                bitMask >>= 1;
            }
            assignedValues[current] = (int)(bitMask - current);
            totalSum += current | assignedValues[current];
            availableNumbers.remove(assignedValues[current]);
        }

        System.out.println(totalSum);
        for (int number = rangeStart; number <= rangeEnd; number++) {
            System.out.print(assignedValues[number] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();

        for (int i = 0; i < testCases; i++) {
            solve(scanner);
        }

        scanner.close();
    }
}
