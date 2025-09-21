
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String[] nm = br.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);

            List<int[]> sets = new ArrayList<>();
            int[] freq = new int[m + 1];

            for (int i = 0; i < n; i++) {
                String[] parts = br.readLine().split(" ");
                int len = Integer.parseInt(parts[0]);
                int[] arr = new int[len];
                for (int j = 0; j < len; j++) {
                    arr[j] = Integer.parseInt(parts[j + 1]);
                    freq[arr[j]]++;
                }
                sets.add(arr);
            }

            boolean valid = true;
            for (int x = 1; x <= m; x++) {
                if (freq[x] == 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                out.append("NO\n");
                continue;
            }

            boolean[] mandatory = new boolean[n];
            for (int i = 0; i < n; i++) {
                for (int x : sets.get(i)) {
                    if (freq[x] == 1) {
                        mandatory[i] = true;
                        break;
                    }
                }
            }

            int nonMandatory = 0;
            for (int i = 0; i < n; i++) {
                if (!mandatory[i])
                    nonMandatory++;
            }

            if (nonMandatory >= 2) {
                out.append("YES\n");
            } else {
                out.append("NO\n");
            }
        }

        System.out.print(out.toString());
    }
}
