import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
 
        while (testCases-- > 0) {
            int segmentCount = scanner.nextInt();
            long[] segmentStarts = new long[segmentCount];
            long[] segmentEnds = new long[segmentCount];
 
            for (int i = 0; i < segmentCount; i++) {
                segmentStarts[i] = scanner.nextLong();
                segmentEnds[i] = scanner.nextLong();
            }
 
            long totalLength = 0;
            for (int i = 0; i < segmentCount; i++) {
                totalLength += (segmentEnds[i] - segmentStarts[i] + 1);
            }
            totalLength += segmentCount / 2L;
 
            Segment[] segments = new Segment[segmentCount];
            for (int i = 0; i < segmentCount; i++) {
                long sumEndsStarts = segmentStarts[i] + segmentEnds[i];
                segments[i] = new Segment(sumEndsStarts, segmentStarts[i], segmentEnds[i]);
            }
 
            Arrays.sort(segments, Comparator.comparingLong(s -> s.sum));
 
            if (segmentCount % 2 == 0) {
                for (int i = 0; i < segmentCount; i++) {
                    totalLength += segmentEnds[i];
                }
                for (int i = 0; i < segmentCount / 2; i++) {
                    totalLength -= segments[i].sum;
                }
                System.out.println(totalLength - segmentCount - segmentCount / 2);
            } else {
                long maxAddition = 0;
                long partialSum = 0;
 
                for (int i = 0; i < segmentCount; i++) {
                    partialSum += segmentEnds[i];
                }
                for (int i = 0; i < segmentCount / 2 + 1; i++) {
                    partialSum -= segments[i].sum;
                }
                for (int i = 0; i < segmentCount / 2 + 1; i++) {
                    maxAddition = Math.max(maxAddition, partialSum + segments[i].start);
                }
                partialSum += segments[segmentCount / 2].sum;
                for (int i = segmentCount / 2 + 1; i < segmentCount; i++) {
                    maxAddition = Math.max(maxAddition, partialSum - segments[i].end);
                }
                System.out.println(totalLength + maxAddition - segmentCount - segmentCount / 2);
            }
        }
        scanner.close();
    }
 
    static class Segment {
        long sum;   // sum of start and end
        long start; // segment start
        long end;   // segment end
 
        public Segment(long sum, long start, long end) {
            this.sum = sum;
            this.start = start;
            this.end = end;
        }
    }
}