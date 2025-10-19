#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int ans = 0;
        vector<int> protected_pos(n, 0);
        int last_one = -k - 1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (i - last_one > k - 1)
                {
                    ans++;
                    protected_pos[i] = 1;
                    last_one = i;
                }
                else
                {
                    last_one = i;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}