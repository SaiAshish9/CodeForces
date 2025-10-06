import java.io.*;
 
public class Main {
    // fast scanner
    static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        FastScanner(InputStream is) { in = is; }
        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }
        int nextInt() throws IOException {
            int c;
            while ((c = read()) <= ' ') if (c == -1) return Integer.MIN_VALUE;
            int sign = 1;
            if (c == '-') { sign = -1; c = read(); }
            int val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }
        long nextLong() throws IOException {
            int c;
            while ((c = read()) <= ' ') if (c == -1) return Long.MIN_VALUE;
            int sign = 1;
            if (c == '-') { sign = -1; c = read(); }
            long val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }
    }
 
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
 
        int t = fs.nextInt();
        while (t-- > 0) {
            int n = fs.nextInt();
            long y = fs.nextLong();
 
            int[] c = new int[n];
            int maxC = 0;
            for (int i = 0; i < n; i++) {
                c[i] = fs.nextInt();
                if (c[i] > maxC) maxC = c[i];
            }
 
            // freq of original tags (index = price)
            int[] freq = new int[maxC + 2]; // +2 to be safe with indexing
            for (int v : c) freq[v]++;
 
            // prefix of frequencies for O(1) range counts
            int[] prefix = new int[maxC + 2];
            for (int i = 1; i <= maxC; i++) prefix[i] = prefix[i - 1] + freq[i];
 
            long best = Long.MIN_VALUE;
 
            // iterate x from 2 to maxC + 1
            for (int x = 2; x <= maxC + 1; x++) {
                long sum = 0L;
                long need = 0L;
                int k = 1;
                // process groups: ci in [(k-1)*x + 1 .. k*x]
                for (int L = 1; L <= maxC; L += x, k++) {
                    int R = L + x - 1;
                    if (R > maxC) R = maxC;
                    int count = prefix[R] - prefix[L - 1];
                    if (count == 0) continue;
                    sum += (long) k * count;
                    // old tags for price k (if k <= maxC)
                    int old = (k <= maxC) ? freq[k] : 0;
                    if (count > old) need += (count - old);
                }
                long income = sum - need * y;
                if (income > best) best = income;
            }
 
            System.out.println(best);
        }
 
    }
}