
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        
        while (t-- > 0) {
            int n = scanner.nextInt();
            int negCount = 0;
            int zeroCount = 0;
            
            for (int i = 0; i < n; i++) {
                int num = scanner.nextInt();
                if (num == -1) {
                    negCount++;
                } else if (num == 0) {
                    zeroCount++;
                }
            }
            
            int operations = 0;
            
            operations += zeroCount;
  
            if (negCount % 2 == 1) {
                operations += 2;
            }
            
            if (zeroCount == 0 && negCount % 2 == 1) {
                operations = 2; 
            }
            
            if (zeroCount > 0 && negCount % 2 == 0) {
                operations = zeroCount;
            }
            
 
            if (zeroCount > 0 && negCount % 2 == 1) {
                operations = zeroCount + 2;
            }
            
            System.out.println(operations);
        }
        
        scanner.close();
    }
}