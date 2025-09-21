import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();

            int[] freq = new int[n + 2];
            int[] dp = new int[n];
            int[] ans = new int[n];
            HashMap<Integer, Integer>[] map = new HashMap[n + 2];
            for (int i = 0; i <= n + 1; i++) map[i] = new HashMap<>();

            for (int i = 0; i < n; i++) {
                freq[a[i]]++;
                map[a[i]].put(freq[a[i]], i);

                if (freq[a[i]] >= a[i]) {
                    int p = freq[a[i]] - a[i] + 1;
                    if (map[a[i]].containsKey(p)) {
                        int pos = map[a[i]].get(p);
                        dp[i] = (pos > 0 ? ans[pos - 1] : 0) + a[i];
                    }
                } else {
                    dp[i] = (i > 0 ? ans[i - 1] : 0);
                }
                ans[i] = Math.max(i > 0 ? ans[i - 1] : 0, dp[i]);
            }
            System.out.println((ans[n - 1]));
        }
    }
}


// public class Main {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int t = sc.nextInt();

//         while (t-- > 0) {
//             int n = sc.nextInt();
//             int[] a = new int[n];
//             TreeMap<Integer, Integer> freq = new TreeMap<>(Collections.reverseOrder());
 
//             for (int i = 0; i < n; i++) {
//                 a[i] = sc.nextInt();
//                 freq.put(a[i], freq.getOrDefault(a[i], 0) + 1);
//             }
 
//             Iterator<Map.Entry<Integer, Integer>> it = freq.entrySet().iterator();
//             while (it.hasNext()) {
//                 Map.Entry<Integer, Integer> entry = it.next();
//                 if (entry.getKey() != 1) {
//                     if (!entry.getKey().equals(entry.getValue())) {
//                         it.remove();
//                     }
//                 }
//             }
            
//             int answer = 0;
//             for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
//                 int x = entry.getKey();
//                 int count = entry.getValue();

//                 if (x == 1) {
//                     answer += x * count;
//                 } else if (x == count) {
//                     boolean initiallyMarked = false;
//                     for (int i = 0; i < n; i++) {
//                         if (a[i] == x) {
//                             initiallyMarked = true;
//                             freq.put(x, freq.get(x) - 1);
//                         } else if (initiallyMarked) {
//                             if (freq.get(x) > 0 && freq.containsKey(a[i])) {
//                                 freq.put(a[i], freq.get(a[i]) - 1);
//                             }
//                         }
//                     }
//                     answer += count;
//                 }

//             }
//             System.out.println(answer);
//         }
//     }
// }

// WWrong answer on test 2
