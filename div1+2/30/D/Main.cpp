#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
string s, t;

bool check(int x)
{
    for (int i = 0, j = -1; i < n; i++)
    {
        while (j + 1 < n && j + 1 - i <= x && t[j + 1] == s[i])
            j++;
        if (j < i)
            return false;
    }
    return true;
}

void construct(int x)
{
    cout << x << '\n';
    for (; x >= 1; x--)
    {
        string s1 = s;
        for (int i = 0, j = -1; i < n; i++)
        {
            while (j + 1 < n && j + 1 - i <= x && t[j + 1] == s[i])
                j++;
            if (j > i)
                s1[i + 1] = s[i];
        }
        s = s1;
        cout << s << "\n";
    }
}

void solve()
{
    cin >> n >> k >> s >> t;
    for (int i = 0; i <= k; i++)
        if (check(i))
        {
            construct(i);
            return;
        }
    cout << "-1\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
