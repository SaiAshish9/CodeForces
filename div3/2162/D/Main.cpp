#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long query(int type, int l, int r) {
    if (l > r) return 0; 
    cout << type << " " << l << " " << r << endl; 
    
    long long response;
    if (!(cin >> response)) {
        exit(0); 
    }
    return response;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    long long sum_a = query(2, 1, n);
    long long sum_p = query(1, 1, n); 
    long long k = sum_a - sum_p;
    
    int l = -1; 
    int low = 1;
    int high = n;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        long long sum_a_prefix = query(2, 1, mid);
        long long sum_p_prefix = query(1, 1, mid);
        long long D_mid = sum_a_prefix - sum_p_prefix;

        if (D_mid > 0) {
            l = mid;
            high = mid - 1; 
        } else { 
            low = mid + 1;
        }
    }
    
    int r = l + (int)k - 1;
    cout << "! " << l << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}
