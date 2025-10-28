#include <iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    if (!(cin >> t)) return 0;
 
    while (t--) {
            int a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) return 0;
 
    if (a == b && b == c && c == d) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    }
 
    return 0;
}