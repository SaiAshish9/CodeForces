#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long get_smallest_power_of_2_greater_than(long long n) {
    if (n == 0) return 1;
    long long p = 1;
    while (p <= n) {
        p <<= 1;
    }
    return p;
}

void solve() {
    long long a, b;
    if (!(cin >> a >> b)) return;

    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    long long C = a ^ b;

    if (C <= a) {
        cout << 1 << "\n";
        cout << C << "\n";
        return;
    }

    long long P = get_smallest_power_of_2_greater_than(a);

    if (b >= P) {
        cout << -1 << "\n";
        return;
    }

    long long x1 = (P - 1) ^ a;
    
    x1 = (P - 1) ^ a;
    long long new_a = a ^ x1; 

    long long x2 = C ^ x1;
    cout << 2 << "\n";
    cout << x1 << " " << x2 << "\n";
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