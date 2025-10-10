#include <bits/stdc++.h>
using namespace std;

bool checkBitwise(long long x, long long y, long long z)
{
    for (int bit = 0; bit < 31; bit++)
    {
        int xb = (x >> bit) & 1;
        int yb = (y >> bit) & 1;
        int zb = (z >> bit) & 1;

        bool ok = false;
        for (int a = 0; a <= 1; a++)
        {
            for (int b = 0; b <= 1; b++)
            {
                for (int c = 0; c <= 1; c++)
                {
                    if ((a & b) == xb && (b & c) == yb && (a & c) == zb)
                    {
                        ok = true;
                        break;
                    }
                }
                if (ok)
                    break;
            }
            if (ok)
                break;
        }
        if (!ok)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        cout << (checkBitwise(x, y, z) ? "YES\n" : "NO\n");
    }
    return 0;
}
