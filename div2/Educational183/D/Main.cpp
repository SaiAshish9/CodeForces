#include <bits/stdc++.h>
using namespace std;

void dfs(int n, vector<int>& curr, vector<vector<int>>& result, int maxParts, int maxValue) {
    int currentSum = accumulate(curr.begin(), curr.end(), 0);

    if (currentSum == n) {
        result.push_back(curr);
        return;
    }
    if (maxParts != -1 && (int)curr.size() == maxParts) return;

    int maxNext = curr.empty() ? n : curr.back();
    if (maxValue != -1) maxNext = min(maxNext, maxValue);
    maxNext = min(maxNext, n - currentSum);

    for (int nextValue = maxNext; nextValue >= 1; nextValue--) {
        curr.push_back(nextValue);
        dfs(n, curr, result, maxParts, maxNext);
        curr.pop_back();
    }
}

vector<vector<int>> enumeratePartition(int n) {
    vector<vector<int>> result;
    vector<int> curr;
    dfs(n, curr, result, -1, -1);
    return result;
}

void solve() {
    long long n, k;
    cin >> n >> k;
    k = n * (n - 1) / 2 - k;

    vector<int> matchingPartition;
    vector<vector<int>> allPartitions = enumeratePartition((int)n);

    for (const auto& currPartition : allPartitions) {
        long long sumPairs = 0;
        for (int size : currPartition) {
            sumPairs += 1LL * size * (size - 1) / 2;
        }
        if (sumPairs == k) {
            matchingPartition = currPartition;
            break;
        }
    }

    if (matchingPartition.empty()) {
        cout << 0 << "\n";
        return;
    }

    long long currentNumber = n;
    vector<long long> resultSequence;
    for (int size : matchingPartition) {
        for (long long num = currentNumber - size + 1; num <= currentNumber; num++) {
            resultSequence.push_back(num);
        }
        currentNumber -= size;
    }

    for (size_t i = 0; i < resultSequence.size(); i++) {
        if (i > 0) cout << " ";
        cout << resultSequence[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
