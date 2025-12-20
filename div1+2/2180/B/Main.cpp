#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        string s = a[0];

        for (int i = 1; i < n; ++i) {
            string front_add = a[i] + s;
            string back_add = s + a[i];

            if (front_add < back_add) {
                s = front_add;
            } else {
                s = back_add;
            }
        }

        cout << s << '\n';
    }
    return 0;
}
