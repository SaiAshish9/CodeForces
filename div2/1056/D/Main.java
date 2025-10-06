import java.util.*;

public class Main {

    static boolean isWinningMove = false;
    static Scanner scanner = new Scanner(System.in);

    static void askQuery(int index1, int index2) {
        if (!isWinningMove) {
            System.out.println((index1 + 1) + " " + (index2 + 1));
            System.out.flush();

            int verdict = scanner.nextInt();
            if (verdict == 1) {
                isWinningMove = true; // Found correct response
            }
        }
    }

    public static void main(String[] args) {
        int testCases = scanner.nextInt();

        while (testCases-- > 0) {
            int arraySize = scanner.nextInt();
            isWinningMove = false;

            for (int gap = 1; gap < arraySize; gap++) {
                for (int leftIndex = 0; leftIndex < arraySize - gap; leftIndex++) {
                    int rightIndex = leftIndex + gap;
                    askQuery(leftIndex, rightIndex);
                }
            }
        }
    }
}
