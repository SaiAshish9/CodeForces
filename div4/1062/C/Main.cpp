#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) return 0;

        vector<int> a(n);
        int odd_count = 0, even_count = 0;

        for (int i = 0; i < n; ++i) {
            if (!(cin >> a[i])) return 0;
            if (a[i] % 2) odd_count++;
            else even_count++;
        }

        if (odd_count && even_count) sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? "" : " ");
        cout << "\n";
    }

    return 0;
}
