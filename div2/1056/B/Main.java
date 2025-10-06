import java.util.*;

public class Main {

    static void asquare(Scanner sc) {
        long n = sc.nextLong();
        long k = sc.nextLong();

        if ((n * n - 1) == k) {
            System.out.println("NO");
            return;
        }

        char[][] grid = new char[(int) n][(int) n];

        for (int i = 0; i < (int) n; i++) {
            for (int j = 0; j < (int) n; j++) {
                if (j == (int) n - 1) {
                    grid[i][j] = 'L';
                } else {
                    grid[i][j] = 'R';
                }
            }
        }

        int c = 0;
        int i = 0, j = 0;
        while (c < k) {
            grid[i][j] = 'L';
            j += 1;
            c += 1;
            if (j == (int) n) {
                j = 0;
                i += 1;
            }
        }

        if ((k % n) == n - 1) {
            int row = (int) (k / n);
            grid[row][(int) n - 1] = 'D';
            grid[row + 1][(int) n - 1] = 'U';
        }

        System.out.println("YES");
        for (int x = 0; x < (int) n; x++) {
            for (int y = 0; y < (int) n; y++) {
                System.out.print(grid[x][y]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        while (t-- > 0) {
            asquare(sc);
        }
    }
}
