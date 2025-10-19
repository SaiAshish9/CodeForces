#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    const ll INF = (ll)4e18;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<ll> pref(n+1);
        for (int i = 1; i <= n; ++i) {
            if (i == 1) pref[i] = a[i];
            else pref[i] = max(pref[i-1], a[i]);
        }

        ll ans = 0;
        for (int i = 1; i <= n; i += 2) { 
            ll left_max = (i - 1 >= 1) ? pref[i-1] : INF;
            ll right_max = (i + 1 <= n) ? pref[i+1] : INF;
            ll limit = min(left_max, right_max) - 1;
            if (a[i] > limit) ans += (a[i] - limit);
        }
        cout << ans << '\n';
    }
    return 0;
}
