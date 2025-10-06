
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while (t-- > 0) {
            int n = sc.nextInt();
            int rem = n % 3;
            if (rem == 0) {
                System.out.println(0);
            } else {
                System.out.println(3 - rem);
            }
        }
        
        sc.close();
    }
}