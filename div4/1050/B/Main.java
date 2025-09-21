import java.util.*;
 
public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            int[] a = new int[n];
            int[] b = new int[m];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            for (int i = 0; i < m; i++) b[i] = sc.nextInt();
 
            int hCrossings = upperBound(a, y);
            int vCrossings = upperBound(b, x);
 
            System.out.println(hCrossings + vCrossings);
        }
    }
    // upperBound returns the number of elements <= 'val'
    static int upperBound(int[] arr, int val) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] <= val) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}