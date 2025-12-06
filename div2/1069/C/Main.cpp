#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;

        int n = s.size(), m = t.size();

        vector<int> t_count(26, 0), s_count(26, 0);
        for (char c : t) t_count[c - 'a']++;
        for (char c : s) s_count[c - 'a']++;

        bool impossible = false;
        for (int i = 0; i < 26; i++) {
            if (s_count[i] > t_count[i]) {
                cout << "Impossible\n";
                impossible = true;
                break;
            }
        }
        if (impossible) continue;

        vector<vector<int>> need(n + 1, vector<int>(26, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int ch = 0; ch < 26; ch++) need[i][ch] = need[i + 1][ch];
            need[i][s[i] - 'a']++;
        }

        vector<int> rem_t = t_count;
        string res;
        int j = 0;

        for (int pos = 0; pos < m; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (rem_t[ch] == 0) continue;

                rem_t[ch]--;
                int new_j = j;
                if (j < n && ch == s[j] - 'a') new_j++;

                bool possible = true;
                for (int c = 0; c < 26; c++) {
                    if (rem_t[c] < need[new_j][c]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    res.push_back(ch + 'a');
                    j = new_j;
                    break;
                } else {
                    rem_t[ch]++;
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}
