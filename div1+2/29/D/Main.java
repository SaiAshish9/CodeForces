import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
 
        while (testCases-- > 0) {
            int n = scanner.nextInt();
            long[] values = new long[n];
            long totalSum = 0;
 
            for (int i = 0; i < n; i++) {
                values[i] = scanner.nextLong();
                totalSum += values[i];
            }
 
            Map<Long, Long> frequencyMap = new HashMap<>();
            for (long value : values) {
                frequencyMap.put(value, frequencyMap.getOrDefault(value, 0L) + 1);
            }
 
            List<Long> oddFrequencies = new ArrayList<>();
            for (Map.Entry<Long, Long> entry : frequencyMap.entrySet()) {
                if (entry.getKey() % 2 == 1) {
                    oddFrequencies.add(entry.getValue());
                }
            }
 
            oddFrequencies.sort(Collections.reverseOrder());
 
            long diff = 0;
            for (int i = 0; i < oddFrequencies.size(); i++) {
                if (i % 2 == 0) {
                    diff += oddFrequencies.get(i);
                } else {
                    diff -= oddFrequencies.get(i);
                }
            }
 
            long firstValue = (totalSum + diff) / 2;
            long secondValue = (totalSum - diff) / 2;
 
            System.out.println(firstValue + " " + secondValue);
        }
 
        scanner.close();
    }
}
