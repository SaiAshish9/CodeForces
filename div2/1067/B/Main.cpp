#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int size_2n = 2 * n;
        map<int, int> counts;

        for (int i = 0; i < size_2n; ++i)
        {
            int a_i;
            cin >> a_i;
            counts[a_i]++;
        }

        int N_odd = 0;
        int N_even = 0;

        for (auto const &[element, count] : counts)
        {
            if (count % 2 != 0)
            {
                N_odd++;
            }
            else
            {
                N_even++;
            }
        }

        int V_max = N_odd + 2 * N_even;

        if (N_odd == 0 && (N_even % 2 != n % 2))
        {
            cout << V_max - 2 << "\n";
        }
        else
        {
            cout << V_max << "\n";
        }
    }
}