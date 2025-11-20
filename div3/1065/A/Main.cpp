#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 != 0) {
            cout << 0 << "\n";
            continue;
        }

        int W_max = n / 4;
        cout << W_max + 1 << "\n";
    }

    return 0;
}
