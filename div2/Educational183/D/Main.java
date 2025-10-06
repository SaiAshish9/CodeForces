import java.util.*;

public class Main {

    static void dfs(int n, List<Integer> curr, List<List<Integer>> result, int maxParts, int maxValue) {
        int currentSum = curr.stream().mapToInt(Integer::intValue).sum();

        if (currentSum == n) {
            result.add(new ArrayList<>(curr));
            return;
        }
        if (maxParts != -1 && curr.size() == maxParts) return;

        int maxNext = curr.isEmpty() ? n : curr.get(curr.size() - 1);
        if (maxValue != -1) maxNext = Math.min(maxNext, maxValue);
        maxNext = Math.min(maxNext, n - currentSum);

        for (int nextValue = maxNext; nextValue >= 1; nextValue--) {
            curr.add(nextValue);
            dfs(n, curr, result, maxParts, maxNext);
            curr.remove(curr.size() - 1);
        }
    }

    static List<List<Integer>> enumeratePartition(int n) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(n, new ArrayList<>(), result, -1, -1);
        return result;
    }

    static void solve(Scanner scanner) {
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        k = n * (n - 1) / 2 - k;

        List<Integer> matchingPartition = new ArrayList<>();

        List<List<Integer>> allPartitions = enumeratePartition((int) n);
        for (List<Integer> currPartition : allPartitions) {
            long sumPairs = 0;
            for (int size : currPartition) {
                sumPairs += (long) size * (size - 1) / 2;
            }
            if (sumPairs == k) {
                matchingPartition = currPartition;
                break;
            }
        }

        if (matchingPartition.isEmpty()) {
            System.out.println(0);
            return;
        }

        long currentNumber = n;
        List<Long> resultSequence = new ArrayList<>();
        for (int size : matchingPartition) {
            for (long num = currentNumber - size + 1; num <= currentNumber; num++) {
                resultSequence.add(num);
            }
            currentNumber -= size;
        }

        for (int i = 0; i < resultSequence.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(resultSequence.get(i));
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        for (int t = 0; t < testCases; t++) {
            solve(scanner);
        }
    }
}
