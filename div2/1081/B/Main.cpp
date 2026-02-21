#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt1 = 0;
        for (char c : s) {
            if (c == '1') cnt1++;
        }

        int cnt0 = n - cnt1;

        if (cnt1 % 2 == 0) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') v.push_back(i + 1);
            }

            cout << v.size() << "\n";
            for (int i = 0; i < (int)v.size(); i++) {
                cout << v[i] << (i + 1 == (int)v.size() ? "" : " ");
            }
            cout << "\n";
        }
        else if (cnt0 % 2 == 1) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') v.push_back(i + 1);
            }

            cout << v.size() << "\n";
            for (int i = 0; i < (int)v.size(); i++) {
                cout << v[i] << (i + 1 == (int)v.size() ? "" : " ");
            }
            cout << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }

}