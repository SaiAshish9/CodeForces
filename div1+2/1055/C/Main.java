import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner(System.in);
        PrintWriter output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int testCases = scanner.nextInt();
        while (testCases-- > 0) {
            int arraySize = scanner.nextInt();
            int queryCount = scanner.nextInt();
            int[] numbers = new int[arraySize + 1];

            for (int i = 1; i <= arraySize; i++) {
                numbers[i] = scanner.nextInt();
            }

            int[] prefixZeros = new int[arraySize + 1];
            int[] prefixOnes = new int[arraySize + 1];
            int[] prefixConsecutiveSame = new int[arraySize + 1];

            for (int i = 1; i <= arraySize; i++) {
                prefixZeros[i] = prefixZeros[i - 1] + (numbers[i] == 0 ? 1 : 0);
                prefixOnes[i] = prefixOnes[i - 1] + (numbers[i] == 1 ? 1 : 0);
                if (i > 1) {
                    prefixConsecutiveSame[i] = prefixConsecutiveSame[i - 1] + (numbers[i] == numbers[i - 1] ? 1 : 0);
                }
            }

            for (int q = 0; q < queryCount; q++) {
                int left = scanner.nextInt();
                int right = scanner.nextInt();

                int countZeros = prefixZeros[right] - prefixZeros[left - 1];
                int countOnes = prefixOnes[right] - prefixOnes[left - 1];

                if (countZeros % 3 != 0 || countOnes % 3 != 0) {
                    output.println(-1);
                } else {
                    int baseOperations = (countZeros + countOnes) / 3;
                    boolean isAlternating = (prefixConsecutiveSame[right] - prefixConsecutiveSame[left]) == 0;
                    if (isAlternating && countZeros > 0 && countOnes > 0) {
                        output.println(baseOperations + 1);
                    } else {
                        output.println(baseOperations);
                    }
                }
            }
        }

        output.flush();
    }

    static class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int pointer = 0, bufferLength = 0;
        private final InputStream inputStream;

        FastScanner(InputStream inputStream) {
            this.inputStream = inputStream;
        }

        private int readByte() throws IOException {
            if (pointer >= bufferLength) {
                bufferLength = inputStream.read(buffer);
                pointer = 0;
                if (bufferLength <= 0) return -1;
            }
            return buffer[pointer++];
        }

        int nextInt() throws IOException {
            int c, sign = 1, value = 0;
            do {
                c = readByte();
            } while (c <= ' ');
            if (c == '-') {
                sign = -1;
                c = readByte();
            }
            while (c > ' ') {
                value = value * 10 + (c - '0');
                c = readByte();
            }
            return value * sign;
        }
    }
}
