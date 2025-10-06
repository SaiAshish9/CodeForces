#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int d = 1; d <= n / 2; ++d) {
        for (int i = 1; i < n; ++i) {
            int j = i + d;
            if (j > n) {
                j = j - n;
            }

            cout << i << " " << j << endl;
            cout.flush(); 

            int response;
            cin >> response;

            if (response == 1) {
                return; 
            }

            if (response == -1) {
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
