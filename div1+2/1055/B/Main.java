import java.util.Scanner;
import java.lang.Math;
 
public class Main {
 
    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        
        while (t-- > 0) {
            long n = scanner.nextLong();
            long rK = scanner.nextLong();
            long cK = scanner.nextLong();
            long rD = scanner.nextLong();
            long cD = scanner.nextLong();
 
            long Tr;
            if (rK > rD) {
                // Krug runs to n. Time = Doran's distance to n.
                Tr = n - rD;
            } else if (rK < rD) {
                // Krug runs to 0. Time = Doran's distance to 0.
                Tr = rD;
            } else { 
                Tr = 0;
            }
 
            long Tc;
            if (cK > cD) {
                // Krug runs to n.
                Tc = n - cD;
            } else if (cK < cD) {
                // Krug runs to 0.
                Tc = cD;
            } else { 
                Tc = 0;
            }
 
            long dr = Math.abs(rK - rD);
            long dc = Math.abs(cK - cD);
 
            long timeRow;
            if (rK != rD) {
                timeRow = Tr;
            } else {
                timeRow = dc; 
            }
 
            long timeCol;
            if (cK != cD) {
                timeCol = Tc;
            } else {
                timeCol = dr;
            }
 
            long survivalTime = Math.max(timeRow, timeCol);
 
            System.out.println(survivalTime);
        }
    }
 
    public static void main(String[] args) {
        solve();
    }
}