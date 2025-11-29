#include <bits/stdc++.h>
using namespace std;

const long long int INF = (long long int)4e18;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        if (s == t)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<pair<int, int>> op1, op2;
        {
            string curr = s;
            while (true)
            {
                vector<char> rc;
                vector<int> rl, rr;
                int i = 0;
                while (i < n)
                {
                    int j = i;
                    while (j < n - 1 && curr[j + 1] == curr[i])
                        ++j;
                    rc.push_back(curr[i]);
                    rl.push_back(i);
                    rr.push_back(j);
                    i = j + 1;
                }

                if (rc.size() <= 1)
                    break;
                int bstl = -1, bstr = -1, bstlen = n + 1;
                for (int cnt = 0; cnt < rc.size(); ++cnt)
                {
                    int rd = 0;
                    while (cnt - rd >= 0 && cnt + rd < rc.size())
                    {
                        int a = cnt - rd;
                        int b = cnt + rd;
                        if (rc[a] != rc[b] || (rr[a] - rl[a]) != (rr[b] - rl[b]))
                            break;
                        if (rr[b] - rl[a] + 1 >= 2 && rr[b] - rl[a] + 1 < bstlen)
                        {
                            bstlen = rr[b] - rl[a] + 1;
                            bstl = rl[a];
                            bstr = rr[b];
                        }
                        ++rd;
                    }
                }

                for (int cnt = 0; cnt < rc.size() - 1; ++cnt)
                {
                    int rd = 0;
                    while (cnt - rd >= 0 && cnt + rd < rc.size() - 1)
                    {
                        int a = cnt - rd;
                        int b = cnt + rd + 1;
                        if (rc[a] != rc[b] || (rr[a] - rl[a]) != (rr[b] - rl[b]))
                            break;
                        if (rr[b] - rl[a] + 1 >= 2 && rr[b] - rl[a] + 1 < bstlen)
                        {
                            bstlen = rr[b] - rl[a] + 1;
                            bstl = rl[a];
                            bstr = rr[b];
                        }
                        ++rd;
                    }
                }

                if (bstl == -1)
                    break;
                op1.push_back({bstl, bstr});

                for (int p = bstl; p <= bstr; ++p)
                    curr[p] = (curr[p] == '0' ? '1' : '0');
            }

            if (curr[0] == '1')
            {
                op1.push_back({0, n - 1});
                for (int p = 0; p < n; ++p)
                    curr[p] = (curr[p] == '0' ? '1' : '0');
            }
        }

        {
            string curr = t;
            while (true)
            {
                vector<char> rc;
                vector<int> rl, rr;
                int i = 0;
                while (i < n)
                {
                    int j = i;
                    while (j < n - 1 && curr[j + 1] == curr[i])
                        ++j;
                    rc.push_back(curr[i]);
                    rl.push_back(i);
                    rr.push_back(j);
                    i = j + 1;
                }

                if (rc.size() <= 1)
                    break;
                int bstl = -1, bstr = -1, bstlen = n + 1;
                for (int cnt = 0; cnt < rc.size(); ++cnt)
                {
                    int rd = 0;
                    while (cnt - rd >= 0 && cnt + rd < rc.size())
                    {
                        int a = cnt - rd;
                        int b = cnt + rd;
                        if (rc[a] != rc[b] || (rr[a] - rl[a]) != (rr[b] - rl[b]))
                            break;
                        if (rr[b] - rl[a] + 1 >= 2 && rr[b] - rl[a] + 1 < bstlen)
                        {
                            bstlen = rr[b] - rl[a] + 1;
                            bstl = rl[a];
                            bstr = rr[b];
                        }
                        ++rd;
                    }
                }

                for (int cnt = 0; cnt < rc.size() - 1; ++cnt)
                {
                    int rd = 0;
                    while (cnt - rd >= 0 && cnt + rd < rc.size() - 1)
                    {
                        int a = cnt - rd;
                        int b = cnt + rd + 1;
                        if (rc[a] != rc[b] || (rr[a] - rl[a]) != (rr[b] - rl[b]))
                            break;
                        if (rr[b] - rl[a] + 1 >= 2 && rr[b] - rl[a] + 1 < bstlen)
                        {
                            bstlen = rr[b] - rl[a] + 1;
                            bstl = rl[a];
                            bstr = rr[b];
                        }
                        ++rd;
                    }
                }

                if (bstl == -1)
                    break;
                op2.push_back({bstl, bstr});

                for (int p = bstl; p <= bstr; ++p)
                    curr[p] = (curr[p] == '0' ? '1' : '0');
            }

            if (curr[0] == '1')
            {
                op2.push_back({0, n - 1});
                for (int p = 0; p < n; ++p)
                    curr[p] = (curr[p] == '0' ? '1' : '0');
            }
        }

        vector<pair<int, int>> ans;
        for (auto &p : op1)
            ans.push_back(p);
        for (int j = op2.size() - 1; j >= 0; --j)
            ans.push_back(op2[j]);

        cout << ans.size() << "\n";

        for (auto j : ans)
            cout << j.first + 1 << " " << j.second + 1 << "\n";
    }
}