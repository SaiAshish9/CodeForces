#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long min_val = LLONG_MAX;
        long long max_val = LLONG_MIN;

        for (int i = 0; i < n; ++i) {
            long long a_i;
            cin >> a_i;
            min_val = min(min_val, a_i);
            max_val = max(max_val, a_i);
        }

        long long x;
        cin >> x;

        if (x >= min_val && x <= max_val) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
