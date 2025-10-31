#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int arraySize;
        cin >> arraySize;

        vector<int> elements(arraySize);
        for (int i = 0; i < arraySize; i++) {
            cin >> elements[i];
            elements[i]--; 
        }

        vector<vector<int>> indexGroups(arraySize);
        for (int i = 0; i < arraySize; i++) {
            indexGroups[elements[i]].push_back(i);
        }

        int totalPairs = 0;

        for (int value = 0; value < arraySize - 1; value++) {
            int maxPossible = int(min(indexGroups[value].size(), indexGroups[value + 1].size()));
            int low = 0, high = maxPossible + 1;

            while (low + 1 < high) {
                int mid = (low + high) >> 1;
                bool isValid = true;

                for (int j = 0; j < mid; j++) {
                    int leftIndex = indexGroups[value][j];
                    int rightIndex = indexGroups[value + 1][int(indexGroups[value + 1].size()) - mid + j];
                    if (leftIndex > rightIndex) {
                        isValid = false;
                        break;
                    }
                }

                if (isValid) {
                    low = mid;
                } else {
                    high = mid;
                }
            }

            totalPairs += low;
            indexGroups[value + 1].resize(int(indexGroups[value + 1].size()) - low);
        }

        cout << totalPairs << '\n';
    }

    return 0;
}
