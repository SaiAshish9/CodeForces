#include <bits/stdc++.h>
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
 
using u128 = unsigned __int128;
using i128 = __int128;
 
int query(int l, int r) {
    std::cout << "? " << l << " " << r << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}
 
void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<std::array<int, 2>> qry(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        qry[i] = {l, r};
    }
    
    {
        std::sort(qry.begin(), qry.end());
        std::vector<std::array<int, 2>> nqry;
        for (auto [l, r] : qry) {
            if (!nqry.empty() && r <= nqry.back()[1]) {
                continue;
            }
            nqry.push_back({l, r});
        }
        qry = std::move(nqry);
    }
    
    q = qry.size();
    
    int lo = 0, hi = q;
    while (lo < hi) {
        int x = (lo + hi) / 2;
        auto [l, r] = qry[x];
        if (query(l, n) < query(1, r)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }
    
    int ans = 0;
    int x = lo;
    if (x < q) {
        auto [l, r] = qry[x];
        ans = std::max(ans, query(l, r));
    }
    if (x > 0) {
        auto [l, r] = qry[x - 1];
        ans = std::max(ans, query(l, r));
    }
    
    std::cout << "! " << ans << std::endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}