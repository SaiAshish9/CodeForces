#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        if (n == 2) {
            cout << (s[0] != s[1] ? 1 : 0) << "\n";
            continue;
        }

        char target_char = s[n - 1];
        int operations_count = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != target_char) {
                operations_count++;
            }
        }

        cout << operations_count << "\n";
    }

    return 0;
}
