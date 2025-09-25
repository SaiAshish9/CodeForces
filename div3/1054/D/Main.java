import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            String s = sc.next();
            
            List<Integer> aPositions = new ArrayList<>();
            List<Integer> bPositions = new ArrayList<>();
            
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == 'a') aPositions.add(i);
                else bPositions.add(i);
            }
            
            long costA = calculateCostToGroup(aPositions);
            long costB = calculateCostToGroup(bPositions);
            
            System.out.println(Math.min(costA, costB));
        }
    }
    
    private static long calculateCostToGroup(List<Integer> positions) {
        int len = positions.size();
        if (len == 0) return 0;
        
        int medianIndex = len / 2;
        int medianPos = positions.get(medianIndex);
        
        long cost = 0;
        
        for(int i = 0; i < len; i++) {
            cost += Math.abs(positions.get(i) - (medianPos - medianIndex + i));
        }
        return cost;
    }
}