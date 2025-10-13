#include <bits/stdc++.h>
using namespace std;

int queryJudge(const vector<int>& querySet) {
    cout << "? " << querySet.size();
    for (int element : querySet) cout << ' ' << element;
    cout << '\n' << flush;
    int response;
    if (!(cin >> response) || response == -1) exit(0);
    return response;
}

void solve() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int numPairs;
        cin >> numPairs;
        int totalElements = 2 * numPairs;

        vector<int> elementValue(totalElements + 1, -1);
        vector<int> unassignedPositions;
        vector<int> valuePosition(numPairs + 1, -1);

        for (int index = totalElements; index >= 1; --index) {
            vector<int> querySet = unassignedPositions;
            querySet.push_back(index);

            int result = queryJudge(querySet);
            if (result == 0) {
                unassignedPositions.push_back(index);
            } else {
                elementValue[index] = result;
                valuePosition[result] = index;
            }
        }

        vector<int> baseSet;
        for (int val = 1; val <= numPairs; ++val) {
            if (valuePosition[val] == -1) exit(0);
            baseSet.push_back(valuePosition[val]);
        }

        for (int index : unassignedPositions) {
            if (elementValue[index] == -1) {
                vector<int> querySet = baseSet;
                querySet.push_back(index);
                elementValue[index] = queryJudge(querySet);
            }
        }

        cout << "! ";
        for (int i = 1; i <= totalElements; ++i) {
            if (i > 1) cout << ' ';
            cout << elementValue[i];
        }
        cout << '\n' << flush;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
