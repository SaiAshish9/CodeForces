#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++)
            cin >> grid[i];

        vector<int> ans(n * m, INF);

        if (n <= m)
        {
            vector<vector<int>> onesInRow(n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == '1')
                        onesInRow[i].push_back(j);
                }
            }

            for (int height = 2; height <= n; height++)
            {
                int numStarts = n - height + 1;
                vector<int> widths(numStarts * m, INF);

                for (int top = 0; top < numStarts; top++)
                {
                    int bottom = top + height - 1;
                    auto &topRow = onesInRow[top];
                    auto &bottomRow = onesInRow[bottom];

                    int i = 0, j = 0, prev = -1;
                    int base = top * m;
                    while (i < (int)topRow.size() && j < (int)bottomRow.size())
                    {
                        if (topRow[i] < bottomRow[j])
                            i++;
                        else if (topRow[i] > bottomRow[j])
                            j++;
                        else
                        {
                            int col = topRow[i];
                            if (prev != -1)
                            {
                                int w = col - prev + 1;
                                int *row = widths.data() + base;
                                for (int c = prev; c <= col; c++)
                                {
                                    if (w < row[c])
                                        row[c] = w;
                                }
                            }
                            prev = col;
                            i++;
                            j++;
                        }
                    }
                }

                vector<int> seq(numStarts), pref(numStarts), suf(numStarts);

                for (int col = 0; col < m; col++)
                {
                    for (int start = 0; start < numStarts; start++)
                        seq[start] = widths[start * m + col];

                    pref[0] = seq[0];
                    for (int k = 1; k < numStarts; k++)
                        pref[k] = min(pref[k - 1], seq[k]);
                    suf[numStarts - 1] = seq[numStarts - 1];
                    for (int k = numStarts - 2; k >= 0; k--)
                        suf[k] = min(suf[k + 1], seq[k]);

                    int limit = min(height - 1, n);
                    for (int i0 = 0; i0 < limit; i0++)
                    {
                        int cand = pref[min(i0, numStarts - 1)];
                        if (cand < INF)
                        {
                            int area = height * cand;
                            int idx = i0 * m + col;
                            ans[idx] = min(ans[idx], area);
                        }
                    }

                    deque<pair<int, int>> dq;
                    for (int u = 0; u < numStarts; u++)
                    {
                        while (!dq.empty() && dq.back().second >= seq[u])
                            dq.pop_back();
                        dq.emplace_back(u, seq[u]);
                        while (!dq.empty() && dq.front().first < u - (height - 1))
                            dq.pop_front();
                        if (u >= height - 1)
                        {
                            int i0 = u;
                            int mn = dq.front().second;
                            if (mn < INF)
                            {
                                int area = height * mn;
                                int idx = i0 * m + col;
                                ans[idx] = min(ans[idx], area);
                            }
                        }
                    }

                    for (int i0 = max(numStarts, 0); i0 < n; i0++)
                    {
                        int s = i0 - (height - 1);
                        if (s >= 0 && s < numStarts)
                        {
                            int cand = suf[s];
                            if (cand < INF)
                            {
                                int area = height * cand;
                                int idx = i0 * m + col;
                                ans[idx] = min(ans[idx], area);
                            }
                        }
                    }
                }
            }
        }
        else
        {
            vector<vector<int>> onesInCol(m);
            for (int j = 0; j < m; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (grid[i][j] == '1')
                        onesInCol[j].push_back(i);
                }
            }

            for (int width = 2; width <= m; width++)
            {
                int numStarts = m - width + 1;
                vector<int> heights(numStarts * n, INF);

                for (int left = 0; left < numStarts; left++)
                {
                    int right = left + width - 1;
                    auto &leftCol = onesInCol[left];
                    auto &rightCol = onesInCol[right];

                    int i = 0, j = 0, prev = -1;
                    int base = left * n;
                    while (i < (int)leftCol.size() && j < (int)rightCol.size())
                    {
                        if (leftCol[i] < rightCol[j])
                            i++;
                        else if (leftCol[i] > rightCol[j])
                            j++;
                        else
                        {
                            int row = leftCol[i];
                            if (prev != -1)
                            {
                                int h = row - prev + 1;
                                int *col = heights.data() + base;
                                for (int r = prev; r <= row; r++)
                                {
                                    if (h < col[r])
                                        col[r] = h;
                                }
                            }
                            prev = row;
                            i++;
                            j++;
                        }
                    }
                }

                vector<int> seq(numStarts), pref(numStarts), suf(numStarts);

                for (int row = 0; row < n; row++)
                {
                    for (int start = 0; start < numStarts; start++)
                        seq[start] = heights[start * n + row];

                    pref[0] = seq[0];
                    for (int k = 1; k < numStarts; k++)
                        pref[k] = min(pref[k - 1], seq[k]);
                    suf[numStarts - 1] = seq[numStarts - 1];
                    for (int k = numStarts - 2; k >= 0; k--)
                        suf[k] = min(suf[k + 1], seq[k]);

                    int limit = min(width - 1, m);
                    for (int j0 = 0; j0 < limit; j0++)
                    {
                        int cand = pref[min(j0, numStarts - 1)];
                        if (cand < INF)
                        {
                            int area = width * cand;
                            int idx = row * m + j0;
                            ans[idx] = min(ans[idx], area);
                        }
                    }

                    deque<pair<int, int>> dq;
                    for (int l = 0; l < numStarts; l++)
                    {
                        while (!dq.empty() && dq.back().second >= seq[l])
                            dq.pop_back();
                        dq.emplace_back(l, seq[l]);
                        while (!dq.empty() && dq.front().first < l - (width - 1))
                            dq.pop_front();
                        if (l >= width - 1)
                        {
                            int j0 = l;
                            int mn = dq.front().second;
                            if (mn < INF)
                            {
                                int area = width * mn;
                                int idx = row * m + j0;
                                ans[idx] = min(ans[idx], area);
                            }
                        }
                    }

                    for (int j0 = max(numStarts, 0); j0 < m; j0++)
                    {
                        int s = j0 - (width - 1);
                        if (s >= 0 && s < numStarts)
                        {
                            int cand = suf[s];
                            if (cand < INF)
                            {
                                int area = width * cand;
                                int idx = row * m + j0;
                                ans[idx] = min(ans[idx], area);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int v = ans[i * m + j];
                if (v >= INF)
                    v = 0;
                cout << v << (j + 1 == m ? '\n' : ' ');
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
