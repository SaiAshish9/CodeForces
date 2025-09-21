import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCases = sc.nextInt();
 
        while (testCases-- > 0) {
            int n = sc.nextInt();
 
            for (int i = n; i >= 1; i--) {
                System.out.print(i + " ");
            }
 
            System.out.print(n);
 
            for (int i = 1; i < n; i++) {
                System.out.print(" " + i);
            }
 
            System.out.println();
        }
 
        sc.close();
    }
}