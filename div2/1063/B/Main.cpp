
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    vector<int> p(n + 1);
    int idx_min = -1, idx_max = -1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
        if (p[i] == 1)
            idx_min = i;
        if (p[i] == n)
            idx_max = i;
    }
    string x_str;
    cin >> x_str;

    for (int i = 1; i <= n; ++i)
    {
        if (x_str[i - 1] == '1')
        {
            if (i == 1 || i == n || p[i] == 1 || p[i] == n)
            {
                cout << -1 << "\n";
                return;
            }
        }
    }

    set<pair<int, int>> ops;
    vector<pair<int, int>> candidates = {
        {1, n},
        {1, idx_min},
        {idx_min, n},
        {1, idx_max},
        {idx_max, n}};

    for (auto cand : candidates)
    {
        int u = cand.first;
        int v = cand.second;
        if (u > v)
            swap(u, v);
        if (u < v)
        {
            ops.insert({u, v});
        }
    }

    cout << ops.size() << "\n";
    for (auto op : ops)
    {
        cout << op.first << " " << op.second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}