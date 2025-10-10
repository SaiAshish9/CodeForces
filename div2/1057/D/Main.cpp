#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

long long tripleCost(long long x, long long y, long long z) {
    return max({x, y, z}) - min({x, y, z});
}

long long solveLinear(const vector<long long>& values, int startIndex, int length) {
    if (length <= 0) return 0;
    if (length == 1) return INF;

    vector<long long> dp(length + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= length; ++i) {
        if (i >= 2 && dp[i - 2] != INF) {
            dp[i] = min(dp[i], dp[i - 2] + abs(values[startIndex + i - 2] - values[startIndex + i - 1]));
        }

        if (i >= 3 && dp[i - 3] != INF) {
            dp[i] = min(dp[i], dp[i - 3] + tripleCost(values[startIndex + i - 3], values[startIndex + i - 2], values[startIndex + i - 1]));
        }
    }

    return dp[length];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;
        vector<long long> values(n);
        for (auto &val : values) cin >> val;

        long long minCost = INF;
        minCost = min(minCost, solveLinear(values, 0, n));

        if (n >= 2) {
            long long costWithFirstExcluded = abs(values[n - 1] - values[0]) + solveLinear(values, 1, n - 2);
            minCost = min(minCost, costWithFirstExcluded);
        }

        if (n >= 3) {
            long long costTripleStart = tripleCost(values[n - 1], values[0], values[1]) + solveLinear(values, 2, n - 3);
            long long costTripleEnd = tripleCost(values[n - 2], values[n - 1], values[0]) + solveLinear(values, 1, n - 3);
            minCost = min({minCost, costTripleStart, costTripleEnd});
        }

        cout << minCost << '\n';
    }
}
