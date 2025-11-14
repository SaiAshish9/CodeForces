#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    const ll BMAX = 2000000000LL;
    const ll END_LIMIT = BMAX + 1;
    while (t--) {
        int n;
        ll a;
        cin >> n >> a;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        vector<pair<ll,int>> ev;
        ev.reserve(2*n);
        for (int i = 0; i < n; ++i) {
            ll d = llabs(v[i] - a);
            if (d == 0) continue;
            ll L = v[i] - d + 1;
            ll R = v[i] + d;
            if (L > BMAX || R <= 0) continue;
            if (L < 0) L = 0;
            if (R > END_LIMIT) R = END_LIMIT;
            if (L < R) {
                ev.emplace_back(L, +1);
                ev.emplace_back(R, -1);
            }
        }

        if (ev.empty()) {
            cout << 0 << '\n';
            continue;
        }

        sort(ev.begin(), ev.end());
        int cur = 0;
        int best = -1;
        ll best_pos = 0;

        size_t i = 0;
        while (i < ev.size()) {
            ll pos = ev[i].first;
            int delta = 0;
            while (i < ev.size() && ev[i].first == pos) {
                delta += ev[i].second;
                ++i;
            }
            cur += delta;
            if (cur > best) {
                best = cur;
                if (pos <= BMAX) best_pos = pos;
                else best_pos = BMAX;
            }
        }

        if (best == -1) cout << 0 << '\n';
        else cout << best_pos << '\n';
    }
    return 0;
}
