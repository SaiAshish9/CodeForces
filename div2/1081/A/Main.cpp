#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int calc(const string& str) {
    int cnt = 1;
    for (int i = 1; i < (int)str.size(); i++) {
        if (str[i] != str[i - 1]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int len;
        cin >> len;

        string word;
        cin >> word;

        int best = 0;

        for (int i = 0; i < len; i++) {
            string cur = word.substr(i) + word.substr(0, i);
            best = max(best, calc(cur));
        }

        cout << best << "\n";
    }

}