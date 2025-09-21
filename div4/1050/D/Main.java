import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int testCases = scanner.nextInt();
        while (testCases-- > 0) {
            int numberCount = scanner.nextInt();
            
            long totalSum = 0;
            List<Integer> oddNumbers = new ArrayList<>();
            
            for (int i = 0; i < numberCount; i++) {
                int currentNumber = scanner.nextInt();
                if (currentNumber % 2 == 0) {
                    totalSum += currentNumber;
                } else {
                    oddNumbers.add(currentNumber);
                }
            }
            
            if (oddNumbers.isEmpty()) {
                System.out.println("0");
                continue;
            }
            
            Collections.sort(oddNumbers);
            int oddCount = oddNumbers.size();
            int startIndex = oddCount / 2;
            
            for (int i = startIndex; i < oddCount; i++) {
                totalSum += oddNumbers.get(i);
            }
            
            System.out.println(totalSum);
        }
        
        scanner.close();
    }
}
