#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_palindrome(const string& t) {
    int m = t.length();
    for (int i = 0; i < m / 2; ++i) {
        if (t[i] != t[m - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool is_non_decreasing(const string& p) {
    if (p.empty()) return true;
    
    bool saw_one = false;
    for (char c : p) {
        if (c == '1') {
            saw_one = true;
        } else if (saw_one && c == '0') {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    for (int m = 0; m < (1 << n); ++m) {
        string p = "";         
        vector<int> p_indices; 
        string x = "";         

        for (int i = 0; i < n; ++i) {
            if ((m >> i) & 1) {
                p += s[i];
                p_indices.push_back(i + 1); 
            } else {
                x += s[i];
            }
        }

        if (is_non_decreasing(p) && is_palindrome(x)) {
            cout << p_indices.size() << "\n";
            for (int i = 0; i < p_indices.size(); ++i) {
                cout << p_indices[i] << (i == p_indices.size() - 1 ? "" : " ");
            }
            cout << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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