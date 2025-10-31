#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        long long X;
        cin >> n >> X;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long S_total = accumulate(a.begin(), a.end(), 0LL);
        long long max_loyalty_level = S_total / X;

        if (max_loyalty_level == 0) {
            cout << 0 << '\n';
            for (int i = 0; i < n; ++i)
                cout << a[i] << (i == n - 1 ? "" : " ");
            cout << '\n';
            continue;
        }

        sort(a.begin(), a.end());
        vector<long long> bonus_items, filler_items;

        for (int i = n - 1; i >= 0; --i) {
            if (bonus_items.size() < max_loyalty_level) bonus_items.push_back(a[i]);
            else filler_items.push_back(a[i]);
        }

        sort(bonus_items.begin(), bonus_items.end());
        long long max_bonus_points = accumulate(bonus_items.begin(), bonus_items.end(), 0LL);

        vector<long long> optimal_order;
        long long current_S = 0;
        int filler_idx = 0;
        long long next_target_level = 1;

        for (size_t i = 0; i < bonus_items.size(); ++i) {
            long long bonus_p = bonus_items[i];
            long long target_S_before_bonus = (next_target_level * X) - bonus_p;

            while (current_S < target_S_before_bonus && filler_idx < filler_items.size()) {
                long long filler_p = filler_items[filler_idx];
                if ((current_S + filler_p) / X == current_S / X) {
                    optimal_order.push_back(filler_p);
                    current_S += filler_p;
                    filler_idx++;
                } else break;
            }

            optimal_order.push_back(bonus_p);
            current_S += bonus_p;
            next_target_level = current_S / X + 1;
        }

        while (filler_idx < filler_items.size())
            optimal_order.push_back(filler_items[filler_idx++]);

        cout << max_bonus_points << '\n';
        for (int i = 0; i < optimal_order.size(); ++i)
            cout << optimal_order[i] << (i == optimal_order.size() - 1 ? "" : " ");
        cout << '\n';
    }

    return 0;
}
