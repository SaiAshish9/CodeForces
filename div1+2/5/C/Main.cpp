#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int64_t sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.rbegin(), a.rend());
        int64_t ans = 0;
        for (int i = 0; i < sum / x; i++)
        {
            ans += a[i];
        }
        sum = 0;
        vector<int> b;
        int l = 0, r = n;
        while (l < r)
        {
            if ((sum + a[l]) / x > sum / x)
            {
                sum += a[l];
                b.push_back(a[l]);
                l += 1;
            }
            else
            {
                r -= 1;
                sum += a[r];
                b.push_back(a[r]);
            }
        }
        cout << ans << '\n';
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}