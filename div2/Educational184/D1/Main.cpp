#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 NMAX = 1000000000000LL;

int64 survivors(int64 M, int64 y, int64 x) {
    int64 len = M;
    for (int64 i = 0; i < x; ++i) {
        if (len == 0) break;
        int64 rem = len / y;
        if (rem == 0) break; 
        len -= rem;
    }
    return len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int64 x, y, k;
        cin >> x >> y >> k;

        if (survivors(NMAX, y, x) < k) {
            cout << -1 << '\n';
            continue;
        }

        int64 lo = 1, hi = NMAX;
        while (lo < hi) {
            int64 mid = lo + (hi - lo) / 2;
            if (survivors(mid, y, x) >= k) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << '\n';
    }
    return 0;
}
