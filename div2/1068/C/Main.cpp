#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define int long long

const int MAXN = 2e5 + 5;

bool is_valid[MAXN];
bool is_minimal[MAXN];
bool covered[MAXN];

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();

    for (int i = 0; i < n; i++)
    {
        is_valid[i] = false;
    }

    for (int i = 0; i < n; ++i)
    {
        int val = a[i];
        int count = k / val;

        if (count > n)
        {
            is_valid[i] = false;
            continue;
        }

        bool ok = true;
        for (int m = 1; m <= count; ++m)
        {
            int target = val * m;
            auto it = lower_bound(a.begin(), a.end(), target);
            if (it == a.end() || *it != target)
            {
                ok = false;
                break;
            }
        }
        is_valid[i] = ok;
    }

    for (int i = 0; i < n; i++)
    {
        is_minimal[i] = is_valid[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (!is_valid[i])
            continue;
        if (!is_minimal[i])
            continue;

        int val = a[i];
        int count = k / val;

        for (int m = 2; m <= count; ++m)
        {
            int target = val * m;

            auto it = lower_bound(a.begin(), a.end(), target);
            if (it != a.end() && *it == target)
            {
                int idx = distance(a.begin(), it);
                if (is_valid[idx])
                {
                    is_minimal[idx] = false;
                }
            }
        }
    }

    vector<int> result_set;
    for (int i = 0; i < n; ++i)
    {
        if (is_minimal[i])
        {
            result_set.push_back(a[i]);
        }
    }

    int covered_count = 0;
    for (int i = 0; i < n; i++)
    {
        covered[i] = false;
    }

    for (int val : result_set)
    {
        int count = k / val;
        for (int m = 1; m <= count; ++m)
        {
            int target = val * m;
            auto it = lower_bound(a.begin(), a.end(), target);
            if (it != a.end() && *it == target)
            {
                int idx = distance(a.begin(), it);
                if (!covered[idx])
                {
                    covered[idx] = true;
                    covered_count++;
                }
            }
        }
    }

    if (covered_count == n)
    {
        cout << result_set.size() << "\n";
        for (int i = 0; i < result_set.size(); ++i)
        {
            cout << result_set[i] << (i == result_set.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
