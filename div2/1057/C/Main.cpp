#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 200002;

int n;
int arr[MAXN];
set<int> uniqueSet;
int leftover[MAXN];
int leftoverCount = 0;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    ll pairSum = 0;
    int pairCount = 0;
    uniqueSet.clear();

    for (int i = 1; i <= n; i++) {
        int value = arr[i];
        auto it = uniqueSet.find(value);
        if (it == uniqueSet.end())
            uniqueSet.insert(value);
        else {
            uniqueSet.erase(it);
            pairCount++;
            pairSum += value;
        }
    }

    leftoverCount = 0;
    for (int x : uniqueSet) leftover[++leftoverCount] = x;
    sort(leftover + 1, leftover + leftoverCount + 1);

    pairSum *= 2;

    if (pairCount == 0) {
        cout << 0 << '\n';
    } else {
        ll maxSum = 0;

        if (pairCount != 1) maxSum = pairSum;

        for (int i = 1; i <= leftoverCount; i++) {
            if (leftover[i] < pairSum)
                maxSum = max(maxSum, pairSum + leftover[i]);
        }

        for (int i = 1; i < leftoverCount; i++) {
            if (leftover[i] + pairSum > leftover[i + 1])
                maxSum = max(maxSum, pairSum + leftover[i] + leftover[i + 1]);
        }

        cout << maxSum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
