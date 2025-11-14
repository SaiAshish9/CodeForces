#include <bits/stdc++.h>
using namespace std;
long long inf = 1000000000000LL;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    long long x, y, k, c, d, ndis, nc;
    for (cin >> T; T > 0; T--)
    {
        cin >> x >> y >> k;
        if (y == 1)
        {
            cout << "-1\n";
            continue;
        }
        if (k <= y - 1)
        {
            cout << k << '\n';
            continue;
        }
        k--;
        c = 0;
        while (c < x)
        {
            d = k / (y - 1);
            ndis = y - 1 - k % (y - 1);
            nc = (ndis + d - 1) / d;
            nc = min(nc, x - c);
            c += nc;
            k += nc * d;
            if (k >= inf)
                break;
        }
        if (k >= inf)
            cout << "-1\n";
        else
            cout << k + 1 << '\n';
    }
    return 0;
}