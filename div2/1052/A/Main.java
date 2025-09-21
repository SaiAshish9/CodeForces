import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] parts = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(parts[i]);
            }
 
            Map<Integer, Integer> freq = new HashMap<>();
            for (int x : a) {
                freq.put(x, freq.getOrDefault(x, 0) + 1);
            }
 
            int ans = 0;
            for (int f = 1; f <= n; f++) {
                int cnt = 0;
                for (int val : freq.values()) {
                    if (val >= f) {
                        cnt++;
                    }
                }
                ans = Math.max(ans, f * cnt);
            }
            out.append(ans).append("\n");
        }
        System.out.print(out.toString());
    }
}
