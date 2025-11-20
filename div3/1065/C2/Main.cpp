#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

int get_bit(int n, int k) {
    return (n >> k) & 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int k = 19; k >= 0; --k) {
        int xor_A_fixed = 0;
        int xor_B_fixed = 0;
        vector<pair<int, int>> Pk;
        vector<int> Pk_indices;

        for (int i = 0; i < n; ++i) {
            int bit_a = get_bit(a[i], k);
            int bit_b = get_bit(b[i], k);

            if (bit_a != bit_b) {
                Pk.push_back({bit_a, bit_b});
                Pk_indices.push_back(i + 1);
            } else {
                xor_A_fixed ^= bit_a;
                xor_B_fixed ^= bit_b;
            }
        }

        int S = Pk.size();
        if (S == 0) continue;

        int fixed_xor_dynamic = 0;
        for (const auto& p : Pk) {
            fixed_xor_dynamic ^= (p.first ^ p.second);
        }

        vector<vector<int>> dp(S + 1, vector<int>(2, 0));

        for (int A_partial = 0; A_partial <= 1; ++A_partial) {
            int B_partial = A_partial ^ fixed_xor_dynamic;
            int A_res = xor_A_fixed ^ A_partial;
            int B_res = xor_B_fixed ^ B_partial;

            if (A_res == 1 && B_res == 0) dp[S][A_partial] = 1;
            else if (A_res == 0 && B_res == 1) dp[S][A_partial] = -1;
            else dp[S][A_partial] = 0;
        }

        for (int i = S - 1; i >= 0; --i) {
            int original_idx = Pk_indices[i];
            bool is_ajisai_turn = (original_idx % 2 != 0);

            int a_bit = Pk[i].first;
            int b_bit = Pk[i].second;

            for (int A_prev = 0; A_prev <= 1; ++A_prev) {
                int A_new_no_swap = A_prev ^ a_bit;
                int outcome_no_swap = dp[i + 1][A_new_no_swap];
                
                int A_new_swap = A_prev ^ b_bit;
                int outcome_swap = dp[i + 1][A_new_swap];

                if (is_ajisai_turn) dp[i][A_prev] = max(outcome_no_swap, outcome_swap);
                else dp[i][A_prev] = min(outcome_no_swap, outcome_swap);
            }
        }

        int final_outcome = dp[0][0];
        
        if (final_outcome == 1) {
            cout << "Ajisai" << "\n";
            return;
        } else if (final_outcome == -1) {
            cout << "Mai" << "\n";
            return;
        }
    }

    cout << "Tie" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
