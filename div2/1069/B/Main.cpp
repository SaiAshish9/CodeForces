#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    
    vector<int> p(n + 1);
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }
    
    // Make p[l-1] and p[r] equal
    p[r] = p[l - 1];
    
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        a[i - 1] = p[i] ^ p[i - 1];
        // Ensure positive (it will be, since adjacent p's are different)
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}