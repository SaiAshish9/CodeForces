import java.util.Scanner;
 
public class Main {
    static Scanner scanner = new Scanner(System.in);
    static long maxSum, maxDiff;
    static int numPoints, totalTestCases;
    static long[] xCoordinates, yCoordinates;
    static StringBuilder outputBuffer = new StringBuilder();
 
    static long query(char direction, long distance) {
        System.out.println("? " + direction + " " + distance);
        System.out.flush();
        return scanner.nextLong();
    }
 
    static void solveTestCase(int currentTest) {
        maxSum = Long.MIN_VALUE;
        maxDiff = Long.MIN_VALUE;
 
        for (int i = 0; i < numPoints; ++i) {
            maxSum = Math.max(maxSum, xCoordinates[i] + yCoordinates[i]);
            maxDiff = Math.max(maxDiff, xCoordinates[i] - yCoordinates[i]);
        }
 
        long largeStep = (long) 1e9;
 
        query('R', largeStep);
        query('R', largeStep);
        query('U', largeStep);
 
        long upResult = query('U', largeStep);
 
        query('D', largeStep);
        query('D', largeStep);
        query('D', largeStep);
 
        long downResult = query('D', largeStep);
 
        maxSum = upResult - 4L * largeStep + maxSum;
        maxDiff = downResult - 4L * largeStep + maxDiff;
 
        long finalX = (maxSum + maxDiff) / 2L;
        long finalY = (maxSum - maxDiff) / 2L;
 
        System.out.println("! " + finalX + " " + finalY);
        System.out.flush();
 
        if (currentTest != totalTestCases) {
            outputBuffer.append("\n");
        }
    }
 
    public static void main(String[] args) {
        totalTestCases = scanner.nextInt();
        for (int testIndex = 1; testIndex <= totalTestCases; testIndex++) {
            numPoints = scanner.nextInt();
            xCoordinates = new long[numPoints];
            yCoordinates = new long[numPoints];
 
            for (int i = 0; i < numPoints; i++) {
                xCoordinates[i] = scanner.nextLong();
                yCoordinates[i] = scanner.nextLong();
            }
 
            solveTestCase(testIndex);
        }
    }
}