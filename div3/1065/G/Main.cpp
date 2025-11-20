#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

typedef long long ll;
const ll MOD = 1000000 + 3;
const int MAX_FACT = MOD;

vector<ll> fact;
vector<ll> invFact;

ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll n) {
    if (n == 0) return 0;
    return power(n, MOD - 2);
}

void precompute(int max_val) {
    fact.resize(max_val + 1);
    invFact.resize(max_val + 1);

    fact[0] = 1;
    for (int i = 1; i <= max_val; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[max_val] = modInverse(fact[max_val]);
    for (int i = max_val - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll fact_mod_M(ll N) {
    if (N == 0) return 1;
    if (N < MOD) return fact[N];
    
    ll res = fact[N % MOD];
    ll q = N / MOD;

    if (q % 2 == 1) {
        res = (MOD - res) % MOD;
    }

    return (res * fact_mod_M(q)) % MOD; 
}

ll multinomial_coefficient(ll N, const vector<ll>& counts) {
    ll power_of_M = N / MOD;
    for (ll count : counts) {
        power_of_M -= count / MOD;
    }

    if (power_of_M > 0) return 0; 
    
    ll N_fact_mod = fact_mod_M(N);
    
    ll denom = 1;
    for (ll count : counts) {
        denom = (denom * fact[count]) % MOD;
    }

    return (N_fact_mod * modInverse(denom)) % MOD;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int k_max = 30;
    for (int i = 0; i < n; ++i) {
        int current_k = floor(log2((double)b[i] / a[i]));
        k_max = min(k_max, current_k);
    }
    if (k_max < 0) k_max = 0;

    ll min_x = -1;
    ll count_x = 0;

    for (int k = 0; k <= k_max; ++k) {
        ll total_increments = 0;
        vector<vector<ll>> I_ji(n, vector<ll>(k + 1, 0)); 
        vector<ll> I_j(k + 1, 0); 
        ll power_of_2k = (1LL << k);

        for (int i = 0; i < n; ++i) {
            ll R_i_k = b[i] - a[i] * power_of_2k;
            
            ll I0_i = R_i_k / power_of_2k;
            ll remainder = R_i_k % power_of_2k;
            
            I_ji[i][0] = I0_i;
            I_j[0] += I0_i;
            total_increments += I0_i;

            for (int m = 0; m < k; ++m) {
                if ((remainder >> m) & 1) {
                    int j = k - m; 
                    I_ji[i][j] = 1;
                    I_j[j]++;
                    total_increments++;
                }
            }
        }

        ll current_x = k + total_increments;

        if (min_x == -1 || current_x < min_x) {
            min_x = current_x;
            count_x = 0;
        }

        if (current_x == min_x) {
            ll Ck = 1;
            
            for (int j = 0; j <= k; ++j) {
                ll I_j_total = I_j[j];
                vector<ll> counts;
                for(int i = 0; i < n; ++i) {
                    counts.push_back(I_ji[i][j]);
                }

                ll W_j = multinomial_coefficient(I_j_total, counts);
                
                Ck = (Ck * W_j) % MOD;
            }
            
            count_x = (count_x + Ck) % MOD;
        }
    }

    cout << min_x << " " << count_x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute(MOD - 1); 

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }
    return 0;
}
