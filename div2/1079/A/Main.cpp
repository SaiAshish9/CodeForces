#include <bits/stdc++.h>
using namespace std;

int getDigitSum(int number) {
    int total = 0;
    while (number > 0) {
        total += number % 10;
        number /= 10;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int target;
        cin >> target;
        int friendlyCount = 0;
        for (int candidate = target; candidate <= target + 200; candidate++) {
            if (candidate - getDigitSum(candidate) == target) {
                friendlyCount++;
            }
        }
        cout << friendlyCount << "\n";
    }
}
