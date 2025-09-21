import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        StringBuilder output = new StringBuilder();

        while (t-- > 0) {
            int n = sc.nextInt();

            List<Integer>[] graph = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) {
                graph[i] = new ArrayList<>();
            }

            int[] indegree = new int[n + 1];

            for (int i = 0; i < n - 1; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                long x = sc.nextLong(), y = sc.nextLong();

                if (x > y) {
                    graph[u].add(v);
                    indegree[v]++;
                } else if (y > x) {
                    graph[v].add(u);
                    indegree[u]++;
                }
                // if x == y, no constraint needed
            }

            // Kahn’s algorithm
            Queue<Integer> q = new ArrayDeque<>();
            for (int i = 1; i <= n; i++) {
                if (indegree[i] == 0)
                    q.add(i);
            }

            int[] result = new int[n + 1];
            int val = n;

            while (!q.isEmpty()) {
                int node = q.poll();
                result[node] = val--; // assign largest remaining number
                for (int next : graph[node]) {
                    indegree[next]--;
                    if (indegree[next] == 0)
                        q.add(next);
                }
            }

            for (int i = 1; i <= n; i++) {
                output.append(result[i]).append(" ");
            }
            output.append("\n");
        }

        System.out.print(output);
        sc.close();
    }
}
