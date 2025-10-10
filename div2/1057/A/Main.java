import java.io.*;
import java.util.*;

public class Main {
    
    private static int maxApples(int[] b) {
        int n = b.length;
        int maxEat = 0;
        
        for (int start = 0; start < n; start++) {
            int lastBeauty = b[start];
            int count = 1; 
            
            boolean[] eaten = new boolean[n];
            eaten[start] = true;
            
            for (int t = 0; t < n - 1; t++) {
                int bestNext = -1;
                int bestIdx = -1;
                
                for (int i = 0; i < n; i++) {
                    if (!eaten[i] && b[i] > lastBeauty) {
                        if (bestNext == -1 || b[i] < bestNext) {
                            bestNext = b[i];
                            bestIdx = i;
                        }
                    }
                }
                
                if (bestIdx == -1) break; 
                eaten[bestIdx] = true;
                lastBeauty = bestNext;
                count++;
            }
            maxEat = Math.max(maxEat, count);
        }
        
        return maxEat;
    }
    
    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner(System.in);
        int t = fs.nextInt();
        StringBuilder sb = new StringBuilder();
        
        while (t-- > 0) {
            int n = fs.nextInt();
            int[] b = new int[n];
            for (int i = 0; i < n; i++) b[i] = fs.nextInt();
            
            int ans = 0;
            ans = Math.max(ans, maxApples(b));
            
            sb.append(ans).append('\n');
        }
        
        System.out.print(sb.toString());
    }
    
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        FastScanner(InputStream in) { br = new BufferedReader(new InputStreamReader(in)); }
        String next() throws IOException {
            while (st == null || !st.hasMoreElements()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
        int nextInt() throws IOException { return Integer.parseInt(next()); }
    }
}
