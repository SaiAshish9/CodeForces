#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<long long> b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }

    vector<int> a(n + 1);

    vector<int> last_pos(n + 1, 0);

    long long b_prev = 0;

    for (int i = 1; i <= n; ++i)
    {
        long long delta = b[i] - b_prev;

        int P = i - (int)delta;

        int chosen_x = -1;
        for (int x = 1; x <= n; ++x)
        {
            if (last_pos[x] == P)
            {
                chosen_x = x;
                break;
            }
        }

        a[i] = chosen_x;
        last_pos[chosen_x] = i;
        b_prev = b[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}