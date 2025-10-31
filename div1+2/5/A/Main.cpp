#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long R0, X, D, N;
        cin >> R0 >> X >> D >> N;

        long long R_min = R0;
        long long R_max = R0;
        string rounds;
        cin >> rounds;
        int rated_rounds_count = 0;

        for (int i = 0; i < N; ++i) {
            char round_type = rounds[i];
            if (round_type == '1') {
                R_min = max(0LL, R_min - D);
                R_max = R_max + D;
                rated_rounds_count++;
            } else {
                if (R_min < X) {
                    long long R_rated_max = min(R_max, X - 1);
                    R_min = max(0LL, R_min - D);
                    R_max = R_rated_max + D;
                    rated_rounds_count++;
                }
            }
        }

        cout << rated_rounds_count << '\n';
    }

    return 0;
}
