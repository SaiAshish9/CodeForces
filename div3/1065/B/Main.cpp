#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> result_a = a;

    if (result_a[0] == -1 && result_a[n - 1] == -1) {
        result_a[0] = 0;
        result_a[n - 1] = 0;
    } else if (result_a[0] == -1) {
        result_a[0] = result_a[n - 1];
    } else if (result_a[n - 1] == -1) {
        result_a[n - 1] = result_a[0];
    }

    for (int i = 1; i < n - 1; ++i) {
        if (result_a[i] == -1) {
            result_a[i] = 0;
        }
    }

    long long min_abs_sum = llabs(result_a[n - 1] - result_a[0]);

    cout << min_abs_sum << endl;
    for (int i = 0; i < n; ++i) {
        cout << result_a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
