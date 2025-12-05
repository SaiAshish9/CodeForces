#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        ll low = 0, high = 0;
        
        for (int i = 0; i < n; i++) {
            ll low_red = low - a[i];
            ll high_red = high - a[i];
            
            ll low_blue = b[i] - high;
            ll high_blue = b[i] - low;
            
            low = min(low_red, low_blue);
            high = max(high_red, high_blue);
        }
        
        cout << high << "\n";
    }
    
    return 0;
}