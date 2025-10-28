#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) return 0;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            if (!(cin >> a[i])) return 0;
        }

        const long long MAX_SEARCH_X = 100000; 
        bool done = false;

        for (long long x = 2; x <= MAX_SEARCH_X; ++x) {
            bool found = false;
            for (long long val : a) {
                if (gcd(val, x) == 1) {
                    found = true;
                    break;
                }
            }
            if (found) {
                cout << x << "\n";
                done = true;
                break;
            }
        }

        if (!done) cout << -1 << "\n";
    }

    return 0;
}
