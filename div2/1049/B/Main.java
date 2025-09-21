import java.util.*; 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        final long S = 999_999_999L; // 10^9 - 1
        while (t-- > 0) {
            long x = sc.nextLong();
            long y = S - x;
            System.out.println(y);
        }
        sc.close();
    }
}