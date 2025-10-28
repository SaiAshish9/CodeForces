#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;

    while (q--) {
        int n;
        if (!(cin >> n)) return 0;

        string s, t;
        if (!(cin >> s >> t)) return 0;

        vector<int> s_counts(26, 0), t_counts(26, 0);
        for (char c : s) s_counts[c - 'a']++;
        for (char c : t) t_counts[c - 'a']++;

        if (s_counts == t_counts) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
