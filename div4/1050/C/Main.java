import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] reqs = new int[n][2];
            for (int i = 0; i < n; i++) {
                reqs[i][0] = sc.nextInt();
                reqs[i][1] = sc.nextInt();
            }
            long points = 0;
            int currentTime = 0;
            int currentSide = 0;
            for (int i = 0; i < n; i++) {
                int a = reqs[i][0];
                int b = reqs[i][1];
                int d = a - currentTime;
                int requiredSide = b;
                int diff = (currentSide != requiredSide) ? 1 : 0;
                int maxRuns = d;
                if (maxRuns % 2 != diff) {
                    maxRuns--;
                }
                points += maxRuns;
                currentTime = a;
                currentSide = requiredSide;
            }
            int dLast = m - currentTime;
            points += dLast;
            System.out.println(points);
        }
    }
}