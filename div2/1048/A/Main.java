import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
 
            if (a == b) {
                System.out.println(0);
            } else if (Math.max(a, b) % Math.min(a, b) == 0) {
                System.out.println(1);
            } else {
                System.out.println(2);
            }
        }
        sc.close();
    }
}
