import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String s = sc.next();

            // quick fail check: consecutive k ones
            if (hasKConsecutiveOnes(s, k)) {
                System.out.println("NO");
                continue;
            }

            System.out.println("YES");
            int[] perm = new int[n];
            int small = 1;     // assign smallest numbers to '1'
            int large = n;     // assign largest numbers to '0'

            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '1') {
                    perm[i] = small++;
                } else {
                    perm[i] = large--;
                }
            }

            for (int i = 0; i < n; i++) {
                System.out.print(perm[i] + (i + 1 == n ? "\n" : " "));
            }
        }
    }

    static boolean hasKConsecutiveOnes(String s, int k) {
        int cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') cnt++;
            else cnt = 0;
            if (cnt >= k) return true;
        }
        return false;
    }
}

// backtracking solution (TLE)