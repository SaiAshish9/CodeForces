
#include <iostream>
#include <algorithm>

using namespace std;

int get_bit(unsigned long long n, int k)
{
    if (k < 0 || k >= 64)
        return 0;
    return (n >> k) & 1ULL;
}

int get_length(unsigned long long n)
{
    if (n == 0)
        return 0;
    return 64 - __builtin_clzll(n);
}

void solve()
{
    unsigned long long n;
    if (!(cin >> n))
        return;

    if (n == 0)
    {
        cout << "YES\n";
        return;
    }

    const int MAX_L = 64;

    for (int L = 1; L <= MAX_L; ++L)
    {
        bool is_L_symmetric = true;

        for (int k = 0; k < L / 2; ++k)
        {
            if (get_bit(n, k) != get_bit(n, L - 1 - k))
            {
                is_L_symmetric = false;
                break;
            }
        }

        if (!is_L_symmetric)
        {
            continue;
        }

        if (L % 2 != 0)
        {
            int middle_bit_index = (L - 1) / 2;
            if (get_bit(n, middle_bit_index) == 1)
            {
                is_L_symmetric = false;
            }
        }

        if (get_length(n) > L)
        {
            continue;
        }

        if (is_L_symmetric)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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