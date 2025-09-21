import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            if (x < y) {
                System.out.println(2);
            } else if (x > y) {
                long m = Math.max(y, x - y);
                if (m + 1 < x) {
                    System.out.println(3);
                } else {
                    System.out.println(-1);
                }
            } else {
                System.out.println(-1);
            }
        }
    }
}
