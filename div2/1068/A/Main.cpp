#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int awake_until = 0;
        int sleep_count = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i-1] == '1') {
                awake_until = max(awake_until, i + k);
            } else {
                if (i > awake_until) sleep_count++;
            }
        }

        cout << sleep_count << "\n";
    }
    return 0;
}
