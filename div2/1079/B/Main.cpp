#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        vector<int> perm(size), target(size);
        vector<int> indexInPerm(size + 1);
        for (int i = 0; i < size; i++) {
            cin >> perm[i];
            indexInPerm[perm[i]] = i;
        }
        for (int i = 0; i < size; i++) {
            cin >> target[i];
        }
        bool isGenerating = true;
        for (int i = 1; i < size; i++) {
            if (target[i] != target[i - 1]) {
                if (indexInPerm[target[i]] < indexInPerm[target[i - 1]]) {
                    isGenerating = false;
                    break;
                }
            }
        }
        cout << (isGenerating ? "YES\n" : "NO\n");
    }
}
