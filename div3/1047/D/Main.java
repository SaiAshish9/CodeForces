import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] b = new int[n];
            for (int i = 0; i < n; i++)
                b[i] = sc.nextInt();

            Map<Integer, List<Integer>> groups = new HashMap<>();
            for (int i = 0; i < n; i++) {
                groups.computeIfAbsent(b[i], k -> new ArrayList<>()).add(i);
            }

            int[] a = new int[n];
            int currentNumber = 1;
            boolean possible = true;

            for (int k : groups.keySet()) {
                List<Integer> indices = groups.get(k);
                if (indices.size() % k != 0) {
                    possible = false;
                    break;
                }
                for (int i = 0; i < indices.size(); i += k) {
                    for (int j = 0; j < k; j++) {
                        a[indices.get(i + j)] = currentNumber;
                    }
                    currentNumber++;
                }
            }

            if (!possible) {
                System.out.println(-1);
            } else {
                for (int i = 0; i < n; i++) {
                    System.out.print(a[i] + " ");
                }
                System.out.println();
            }
        }
    }
}
