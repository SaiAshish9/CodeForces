import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
 
        while (testCases-- > 0) {
            int size = scanner.nextInt();
            int[] inputArray = new int[size];
            
            for (int i = 0; i < size; i++) {
                inputArray[i] = scanner.nextInt();
            }
 
            int[] minAdjustedValues = new int[size + 1];
            long totalDifference = 0;
 
            for (int i = 0; i < size; i += 2) {
                int minValue = inputArray[i];
                
                if (i >= 2) {
                    minValue = Math.min(minValue, inputArray[i - 1] - minAdjustedValues[i - 2]);
                }
                if (i + 1 < size) {
                    minValue = Math.min(minValue, inputArray[i + 1]);
                }
 
                minAdjustedValues[i] = minValue;
                totalDifference += (inputArray[i] - minAdjustedValues[i]);
            }
 
            System.out.println(totalDifference);
        }
    }
}