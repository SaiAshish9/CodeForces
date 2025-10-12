#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> counts;
    int max_val = -1;

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        counts[a]++;
        if (a > max_val)
        {
            max_val = a;
        }
    }

    int min_score = 0;

    for (int m = 0; m <= 101; ++m)
    {
        if (counts.find(m) == counts.end())
        {
            min_score = m;
            break;
        }
    }

    cout << min_score << "\n";
}

int main()
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