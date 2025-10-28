#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) return 0;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (!(cin >> a[i])) return 0;
        }

        vector<long long> c(n + 1), C(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (!(cin >> c[i])) return 0;
            C[i] = C[i - 1] + c[i];
        }

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[j] <= a[i] || j == 0) {
                    long long cost = dp[j] + (C[i - 1] - C[j]);
                    dp[i] = min(dp[i], cost);
                }
            }
        }

        long long min_total_cost = INF;
        for (int j = 0; j <= n; ++j) {
            if (dp[j] == INF && j > 0) continue;
            long long cost = dp[j] + (C[n] - C[j]);
            min_total_cost = min(min_total_cost, cost);
        }

        cout << min_total_cost << "\n";
    }

    return 0;
}
