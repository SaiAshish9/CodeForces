#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_A = 200000 + 5;
const int INF = 1e9;

vector<int> primes;
bool is_composite[MAX_A];
int min1[MAX_A], min2[MAX_A];

void sieve()
{
    for (int i = 2; i < MAX_A; i++)
    {
        if (!is_composite[i])
        {
            primes.push_back(i);
            for (int j = i + i; j < MAX_A; j += i)
            {
                is_composite[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
        }

        for (int p : primes)
        {
            min1[p] = INF;
            min2[p] = INF;
        }

        for (int i = 0; i < n; i++)
        {
            for (int add = 0; add <= 2; add++)
            {
                int val = a[i] + add;
                int tmp = val;
                for (int p : primes)
                {
                    if (p * p > tmp)
                        break;
                    if (tmp % p == 0)
                    {
                        int cost = add;
                        if (cost < min1[p])
                        {
                            min2[p] = min1[p];
                            min1[p] = cost;
                        }
                        else if (cost < min2[p])
                        {
                            min2[p] = cost;
                        }
                        while (tmp % p == 0)
                            tmp /= p;
                    }
                }
                if (tmp > 1)
                {
                    int p = tmp;
                    int cost = add;
                    if (cost < min1[p])
                    {
                        min2[p] = min1[p];
                        min1[p] = cost;
                    }
                    else if (cost < min2[p])
                    {
                        min2[p] = cost;
                    }
                }
            }
        }

        int ans = INF;
        for (int p : primes)
        {
            if (min2[p] < INF)
            {
                ans = min(ans, min1[p] + min2[p]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}