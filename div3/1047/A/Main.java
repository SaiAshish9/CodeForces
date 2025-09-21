import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int k = sc.nextInt();
            int x = sc.nextInt();

            for (int i = 0; i < k; i++) {
                if ((x - 1) % 3 == 0 && ((x - 1) / 3) % 2 == 1) {
                    x = (x - 1) / 3; // valid odd reverse
                } else {
                    x = x * 2; // safe reverse
                }
            }

            System.out.println(x);
        }
    }
}
