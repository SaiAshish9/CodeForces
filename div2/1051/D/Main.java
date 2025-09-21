import java.util.*;
 
public class Main {
    static final int MOD = 1_000_000_007;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
 
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
 
            long ans = 0;
 
            int total = 1 << n;
            for (int mask = 0; mask < total; mask++) {
                if (isGood(mask, a, n)) {
                    ans++;
                    if (ans >= MOD) ans -= MOD;
                }
            }
 
            System.out.println(ans);
        }
    }
 
    // Check if subsequence defined by mask is good
    private static boolean isGood(int mask, int[] a, int n) {
        List<Integer> nodes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) nodes.add(i);
        }
        int m = nodes.size();
        if (m <= 2) return true;
 
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < m; i++) g.add(new ArrayList<>());
 
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int u = nodes.get(i), v = nodes.get(j);
                if (a[u] > a[v]) {
                    g.get(i).add(j);
                    g.get(j).add(i);
                }
            }
        }
 
        int[] color = new int[m];
        Arrays.fill(color, -1);
 
        for (int i = 0; i < m; i++) {
            if (color[i] == -1) {
                if (!bfsCheck(i, g, color)) return false;
            }
        }
        return true;
    }
 
    private static boolean bfsCheck(int start, List<List<Integer>> g, int[] color) {
        Queue<Integer> q = new ArrayDeque<>();
        q.add(start);
        color[start] = 0;
 
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : g.get(u)) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.add(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
        return true;
    }
}