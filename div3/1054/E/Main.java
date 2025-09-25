import java.util.*;

public class Main {

    static long countSubarraysAtMostK(int[] arr, int n, int k, int lengthLimit) {
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0;
        int distinctCount = 0;
        long count = 0;

        for (int right = 0; right < n; right++) {
            freq.put(arr[right], freq.getOrDefault(arr[right], 0) + 1);
            if (freq.get(arr[right]) == 1)
                distinctCount++;

            while (distinctCount > k) {
                freq.put(arr[left], freq.get(arr[left]) - 1);
                if (freq.get(arr[left]) == 0)
                    distinctCount--;
                left++;
            }

            while (right - left + 1 > lengthLimit) {
                freq.put(arr[left], freq.get(arr[left]) - 1);
                if (freq.get(arr[left]) == 0)
                    distinctCount--;
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int l = sc.nextInt();
            int r = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            long atMostK_r = countSubarraysAtMostK(arr, n, k, r);
            long atMostK_l_1 = countSubarraysAtMostK(arr, n, k, l - 1);

            long atMostKMinus1_r = countSubarraysAtMostK(arr, n, k - 1, r);
            long atMostKMinus1_l_1 = countSubarraysAtMostK(arr, n, k - 1, l - 1);

            long result = (atMostK_r - atMostK_l_1) - (atMostKMinus1_r - atMostKMinus1_l_1);
            System.out.println(result);
        }
    }
}