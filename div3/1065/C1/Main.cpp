#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int fixed_xor_A = 0;
    int fixed_xor_B = 0;
    
    vector<pair<int, int>> P_dynamic;
    vector<int> P_indices;

    for (int i = 0; i < n; ++i) {
        int bit_a = a[i];
        int bit_b = b[i];

        if (bit_a != bit_b) {
            P_dynamic.push_back({bit_a, bit_b});
            P_indices.push_back(i + 1);
        } else {
            fixed_xor_A ^= bit_a;
            fixed_xor_B ^= bit_b;
        }
    }

    int S = P_dynamic.size();
    
    if (S == 0) {
        if (fixed_xor_A > fixed_xor_B) cout << "Ajisai\n";
        else if (fixed_xor_B > fixed_xor_A) cout << "Mai\n";
        else cout << "Tie\n";
        return;
    }

    int fixed_xor_dynamic = S % 2;

    vector<vector<int>> dp(S + 1, vector<int>(2, 0));

    for (int A_partial = 0; A_partial <= 1; ++A_partial) {
        int B_partial = A_partial ^ fixed_xor_dynamic;
        
        int A_res = fixed_xor_A ^ A_partial;
        int B_res = fixed_xor_B ^ B_partial;

        if (A_res > B_res) dp[S][A_partial] = 1;
        else if (B_res > A_res) dp[S][A_partial] = -1;
        else dp[S][A_partial] = 0;
    }

    for (int i = S - 1; i >= 0; --i) {
        int original_idx = P_indices[i];
        bool is_ajisai_turn = (original_idx % 2 != 0);

        int a_bit = P_dynamic[i].first;
        int b_bit = P_dynamic[i].second;

        for (int A_prev = 0; A_prev <= 1; ++A_prev) {
            int A_new_no_swap = A_prev ^ a_bit;
            int outcome_no_swap = dp[i + 1][A_new_no_swap];
            
            int A_new_swap = A_prev ^ b_bit;
            int outcome_swap = dp[i + 1][A_new_swap];

            if (is_ajisai_turn) {
                dp[i][A_prev] = max(outcome_no_swap, outcome_swap);
            } else {
                dp[i][A_prev] = min(outcome_no_swap, outcome_swap);
            }
        }
    }

    int final_outcome = dp[0][0];
    
    if (final_outcome == 1) cout << "Ajisai\n";
    else if (final_outcome == -1) cout << "Mai\n";
    else cout << "Tie\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
