import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
 
        while (t-- > 0) {
            int a = sc.nextInt(), b = sc.nextInt();
            int c = sc.nextInt(), d = sc.nextInt();
 
            int riolFirst = a, kdoiFirst = b;
            int riolSecond = c - a, kdoiSecond = d - b;
 
            if (isValid(riolFirst, kdoiFirst) && isValid(riolSecond, kdoiSecond)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
 
    private static boolean isValid(int rGoals, int kGoals) {
        // If either side has more than twice the other + 2,
        // then 3 consecutive goals are unavoidable
        if (rGoals > 2 * (kGoals + 1)) return false;
        if (kGoals > 2 * (rGoals + 1)) return false;
        return true;
    }
}