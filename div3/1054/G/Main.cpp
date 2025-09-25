
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
 
int lowerBound(const vector<int> &arr, int target) {
    int low = 0, high = (int)arr.size();
    while(low < high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= target) high = mid;
        else low = mid + 1;
    }
    return low;
}
 
int upperBound(const vector<int> &arr, int target) {
    int low = 0, high = (int)arr.size();
    while(low < high) {
        int mid = (low + high) / 2;
        if(arr[mid] > target) high = mid;
        else low = mid + 1;
    }
    return low;
}
 
int countInRange(const vector<int> &pos, int l, int r) {
    int left = lowerBound(pos, l);
    int right = upperBound(pos, r);
    return right - left;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t; cin >> t;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        unordered_map<int, vector<int>> positions;
 
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            positions[a[i]].push_back(i + 1);
        }
 
        while(q--) {
            int l, r; cin >> l >> r;
            int len = r - l + 1;
            int threshold = len / 3 + 1;
 
            unordered_set<int> candidates;
            int trials = 40;
            uniform_int_distribution<int> dist(l, r);
 
            for(int i=0; i<trials; i++) {
                int pos = dist(rng);
                candidates.insert(a[pos - 1]);
            }
 
            vector<int> ans;
            for(auto &c : candidates) {
                const auto &posList = positions[c];
                int cnt = countInRange(posList, l, r);
                if(cnt >= threshold) {
                    ans.push_back(c);
                }
            }
 
            if(ans.empty()) {
                cout << -1 << "\n";
            } else {
                sort(ans.begin(), ans.end());
                for(auto val : ans) cout << val << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}