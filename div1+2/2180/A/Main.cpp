#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long l, a, b;
        cin >> l >> a >> b;

        long long g = std::gcd(b, l);
        long long target_remainder = a % g;
        long long max_prize = (l - 1) - ((l - 1 - target_remainder + g) % g);

        cout << max_prize << '\n';
    }
    return 0;
}
