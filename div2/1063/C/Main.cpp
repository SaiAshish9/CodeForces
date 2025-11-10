#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> a1(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a1[i];
    vector<int> a2(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a2[i];
 
    int N_total = 2 * n;
 
    vector<int> pmax1(n + 1, 0);
    vector<int> pmin1(n + 1, N_total + 1);
    for (int i = 1; i <= n; ++i) {
        pmax1[i] = max(pmax1[i - 1], a1[i]);
        pmin1[i] = min(pmin1[i - 1], a1[i]);
    }
 
    vector<int> smax2(n + 2, 0);
    vector<int> smin2(n + 2, N_total + 1);
    for (int i = n; i >= 1; --i) {
        smax2[i] = max(smax2[i + 1], a2[i]);
        smin2[i] = min(smin2[i + 1], a2[i]);
    }
 
    vector<int> m_k(n + 1);
    vector<int> M_k(n + 1);
    for (int k = 1; k <= n; ++k) {
        M_k[k] = max(pmax1[k], smax2[k]);
        m_k[k] = min(pmin1[k], smin2[k]);
    }
 
    vector<int> Max_m_at_M(N_total + 1, 0);
    for (int k = 1; k <= n; ++k) {
        Max_m_at_M[M_k[k]] = max(Max_m_at_M[M_k[k]], m_k[k]);
    }
 
    vector<int> L_r(N_total + 1, 0);
    for (int r = 1; r <= N_total; ++r) {
        L_r[r] = max(L_r[r - 1], Max_m_at_M[r]);
    }
 
    long long total_count = 0;
    for (int r = 1; r <= N_total; ++r) {
        total_count += min(r, L_r[r]);
    }
 
    cout << total_count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
