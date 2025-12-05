#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int rec(int N, int K)
{
    if (K == 0 || N == 0)
    {
        return 0;
    }
    if (__builtin_popcount(N) == 1)
    {
        return K;
    }
    int lsb = (N & -N);
    int take = N + lsb;
    int leave = take - (take & -take);
    return max(rec(take, K - 1) + __builtin_popcount(N ^ take) - 1, rec(leave, K));
};

void solve()
{
    int N, K;
    cin >> N >> K;
    cout << rec(N, K) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N = 1;
    cin >> N;
    while (N--)
    {
        solve();
    }
    return 0;
}