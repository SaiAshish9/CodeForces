import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            String s = scanner.next();
            char[] sortedChars = s.toCharArray();
            Arrays.sort(sortedChars);
            String sorted = new String(sortedChars);
            int diff = 0;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) != sorted.charAt(i)) {
                    diff++;
                }
            }
            System.out.println(diff / 2);
        }
    }
}
