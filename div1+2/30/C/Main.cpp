#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Monster {
    long long b;
    long long c;
};

bool compareMonsters(const Monster& m1, const Monster& m2) {
    return m1.b < m2.b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, m;
        if (!(cin >> n >> m)) return 0;

        multiset<long long> swords;
        for (int i = 0; i < n; ++i) {
            long long a_i;
            cin >> a_i;
            swords.insert(a_i);
        }

        vector<long long> b(m);
        for (int i = 0; i < m; ++i) cin >> b[i];

        vector<long long> c(m);
        for (int i = 0; i < m; ++i) cin >> c[i];

        vector<Monster> r_monsters;
        vector<long long> z_monsters;

        for (int i = 0; i < m; ++i) {
            if (c[i] > 0) {
                r_monsters.push_back({b[i], c[i]});
            } else {
                z_monsters.push_back(b[i]);
            }
        }

        sort(r_monsters.begin(), r_monsters.end(), compareMonsters);
        sort(z_monsters.begin(), z_monsters.end());

        int kills = 0;

        for (const auto& monster : r_monsters) {
            long long b_i = monster.b;
            long long c_i = monster.c;

            if (swords.empty()) break;

            auto it = swords.lower_bound(b_i);

            if (it != swords.end()) {
                long long used_sword = *it;
                swords.erase(it);
                swords.insert(max(used_sword, c_i));
                kills++;
            }
        }

        for (long long b_i : z_monsters) {
            if (swords.empty()) break;

            auto it = swords.lower_bound(b_i);
            if (it != swords.end()) {
                swords.erase(it);
                kills++;
            } else {
                break;
            }
        }

        cout << kills << "\n";
    }

    return 0;
}
