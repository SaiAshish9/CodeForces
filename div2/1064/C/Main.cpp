#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int pos = 0;
        for (int i = 1; i < n; ++i)
            if (a[i] > a[pos]) pos = i;

        vector<ll> v;
        v.reserve(n);
        for (int i = pos + 1; i < pos + 1 + n; ++i) {
            v.push_back(a[i % n]);
        }

        const ll INF = (1LL<<62);
        vector<ll> st;
        st.reserve(n);
        ll cost = 0;

        for (ll x : v) {
            while (!st.empty() && st.back() <= x) {
                ll y = st.back(); st.pop_back();
                if (st.empty()) {
                    cost += min(INF, x);
                } else {
                    cost += min(st.back(), x);
                }
            }
            st.push_back(x);
        }

        while (st.size() > 1) {
            ll y = st.back(); st.pop_back();
            cost += st.back();
        }

        cout << cost << '\n';
    }
    return 0;
}
