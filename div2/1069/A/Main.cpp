#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_set<int> S;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            S.insert(a[i]);
        }

        int D = S.size();  // distinct count

        while (true) {
            if (S.count(D)) {
                // stabilized
                cout << D << "\n";
                break;
            } else {
                // new color introduced
                S.insert(D);
                D++;
            }
        }
    }
    return 0;
}
