#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long a, b, n;
        cin >> a >> b >> n;
        long long k = a / b;
        if (n <= k || a == b) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
    return 0;
}
