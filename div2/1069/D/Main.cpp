#include <bits/stdc++.h>
using namespace std;

long double PI = acos(-1);
long double DEL = 1e-12;
long long M = 1e9 + 7;
const long long N = 3e5 + 10;
#define all(a) a.begin(), a.end()
#define sq(a) ((a) * (a))
#define double long double
#define sp << " " <<
#define int long long

pair<int, int> dp[365][365];
vector<int> pos[365];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for (int cas = 1; cas <= tc; ++cas)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            int lim = min(a[i], k);
            for (int v = 1; v <= lim; ++v)
            {
                pos[v].push_back(i);
            }
        }

        for (int c = 0; c <= k; ++c)
        {
            for (int v = 0; v <= c; ++v)
            {
                dp[c][v] = {n + 1, -2e18};
            }
        }

        dp[0][0] = {0, 0};

        for (int c = 0; c <= k; ++c)
        {
            for (int v = 0; v <= c; ++v)
            {
                if (dp[c][v].first > n)
                    continue;

                int idx = dp[c][v].first;
                int val = dp[c][v].second;

                for (int nv = v + 1; nv <= k - c; ++nv)
                {
                    auto it = upper_bound(all(pos[nv]), idx);
                    if (it != pos[nv].end())
                    {
                        int p = *it;
                        int nc = c + nv;
                        int nval = val + (p - 1 - idx) * v + nv;

                        if (p < dp[nc][nv].first)
                        {
                            dp[nc][nv] = {p, nval};
                        }
                        else if (p == dp[nc][nv].first)
                        {
                            dp[nc][nv].second = max(dp[nc][nv].second, nval);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int c = 0; c <= k; ++c)
        {
            for (int v = 0; v <= c; ++v)
            {
                if (dp[c][v].first <= n)
                {
                    int idx = dp[c][v].first;
                    int val = dp[c][v].second;
                    int cur = val + (n - idx) * v;
                    ans = max(ans, cur);
                }
            }
        }

        cout << ans << endl;

        for (int v = 1; v <= k; ++v)
            pos[v].clear();
    }
}
