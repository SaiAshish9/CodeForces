import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            long a = sc.nextLong();
            long b = sc.nextLong();
 
            boolean blueCentered = ((n - b) % 2 == 0);
            boolean redFitsOrCentered = (a <= b) || ((n - a) % 2 == 0);
            boolean possible = blueCentered && redFitsOrCentered;
 
            System.out.println(possible ? "YES" : "NO");
        }
        sc.close();
    }
}

/*
→Judgement Protocol
Test: #1, time: 156 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
7
5 3 1
4 1 2
7 7 4
8 3 7
1 1 1
1000000000 1000000000 1000000000
3 2 1

Output
YES
YES
NO
NO
YES
YES
NO

Checker Log
ok 7 token(s): yes count is 4, no count is 3
*/
