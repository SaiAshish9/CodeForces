#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n+1), pref(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pref[i] = pref[i-1] + a[i];
        }
        ll base = pref[n];
        ll bestB = LLONG_MIN;
        ll maxGain = 0;
        for (int r = 1; r <= n; ++r) {
            ll l = r;
            ll B_r = l - l*l + pref[l-1];
            if (B_r > bestB) bestB = B_r;
            ll A_r = 1LL*r*r + r - pref[r];
            ll cand = A_r + bestB;
            if (cand > maxGain) maxGain = cand;
        }
        cout << base + maxGain << '\n';
    }
    return 0;
}
