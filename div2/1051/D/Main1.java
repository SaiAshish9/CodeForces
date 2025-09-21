import java.util.*;
 
public class Main {
    static final int MOD = 1000000007;
    static final int MAX_SIZE = 105;
    static long[][][] dpCache = new long[MAX_SIZE][MAX_SIZE][MAX_SIZE];
    static int[] sequence;
    static int sequenceLength;
 
    static long solveDP(int index, int firstMax, int secondMax) {
        if (index == sequenceLength) return 1;
        if (dpCache[index][firstMax][secondMax] != -1) {
            return dpCache[index][firstMax][secondMax];
        }
 
        long ways = solveDP(index + 1, firstMax, secondMax);
 
        int newFirstMax = firstMax;
        int newSecondMax = secondMax;
 
        if (sequence[index] > firstMax) newFirstMax = sequence[index];
        if (sequence[index] < firstMax && sequence[index] > secondMax) {
            newSecondMax = sequence[index];
        }
 
        ways %= MOD;
 
        if (sequence[index] < secondMax) {
            return dpCache[index][firstMax][secondMax] = ways;
        }
 
        ways += solveDP(index + 1, newFirstMax, newSecondMax);
        ways %= MOD;
 
        return dpCache[index][firstMax][secondMax] = ways;
    }
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCases = sc.nextInt();
 
        while (testCases-- > 0) {
            sequenceLength = sc.nextInt();
 
            for (int i = 0; i <= sequenceLength; i++) {
                for (int j = 0; j <= sequenceLength; j++) {
                    Arrays.fill(dpCache[i][j], -1);
                }
            }
 
            sequence = new int[sequenceLength];
            for (int i = 0; i < sequenceLength; i++) {
                sequence[i] = sc.nextInt();
            }
 
            System.out.println(solveDP(0, 0, 0));
        }
        sc.close();
    }
}
