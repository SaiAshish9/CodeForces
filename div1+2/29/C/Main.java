
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        
        while (testCases-- > 0) {
            solve(scanner);
        }
        
        scanner.close();
    }
 
    private static void solve(Scanner scanner) {
        int length = scanner.nextInt();
        String binaryString = scanner.next();
        
        boolean isValid = true;
        boolean currentBlockIsOnes = (binaryString.charAt(0) == '1');
        int zeroCount = 0;
 
        for (int i = 0; i < length; i++) {
            if (binaryString.charAt(i) == '0') {
                zeroCount++;
            }
            
            if (i == 0) {
                continue;
            }
            
            if (binaryString.charAt(i) == '0' && binaryString.charAt(i - 1) == '0') {
                currentBlockIsOnes = false;
            }
            
            if (binaryString.charAt(i) == '1' && binaryString.charAt(i - 1) == '1') {
                if (currentBlockIsOnes && zeroCount % 2 == 1) {
                    isValid = false;
                }
                currentBlockIsOnes = true;
                zeroCount = 0;
            }
        }
        
        if (currentBlockIsOnes && zeroCount % 2 == 1 && binaryString.charAt(length - 1) == '1') {
            isValid = false;
        }
        
        System.out.println(isValid ? "YES" : "NO");
    }
}
