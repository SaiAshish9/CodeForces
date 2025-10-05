#include <bits/stdc++.h>
using namespace std;

const int MOD = 676767677;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        bool valid_diff = true;
        for (int i = 2; i <= n; i++) {
            if (abs(a[i] - a[i - 1]) > 1) {
                valid_diff = false;
                break;
            }
        }
        
        if (!valid_diff) {
            cout << "0\n";
            continue;
        }
        
        set<int> cand1, cand2;
        cand1.insert(n - a[1]);
        cand1.insert(n - a[1] + 1);
        cand2.insert(a[n]);
        cand2.insert(a[n] - 1);
        
        int count = 0;
        for (int L : cand1) {
            if (cand2.count(L) && L >= 0 && L <= n) {
                vector<int> x(n + 1, 0);
                x[0] = 0;
                x[1] = a[1] + L - n;
                if (x[1] < 0 || x[1] > 1) continue;
                
                bool ok = true;
                for (int i = 2; i <= n; i++) {
                    x[i] = a[i] + L - (n - i + 1) - x[i - 1];
                    if (x[i] < x[i - 1] || x[i] > L || x[i] - x[i - 1] > 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok && x[n] == L) {
                    count++;
                }
            }
        }
        
        cout << count % MOD << "\n";
    }
    
    return 0;
}