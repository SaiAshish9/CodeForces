#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int max_element = 0; 

    for (int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;
        
        if (a_i > max_element) {
            max_element = a_i;
        }
    }
    cout << max_element << endl;
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