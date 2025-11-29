#include<bits/stdc++.h>
using namespace std;

const long long int INF = (long long int)4e18;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        long long int k;
        cin >> n >> k;
        
        vector<long long int> arr(n), arr1(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        for(int i = 0; i < n; ++i)
            cin >> arr1[i];
            
        vector<long long int> pr1(n), pr2(n);
        for(int i = 0; i < n; ++i)
        {
            if(i == 0)
                pr1[i] = arr[i];
            else
                pr1[i] = max(arr[i], pr1[i - 1] + arr[i]);
            pr2[i] = (i == 0 ? pr1[i] : max(pr2[i - 1], pr1[i]));
        }
        
        long long int st = pr2[n - 1];
        if(k % 2 == 0)
        {
            cout << st << "\n";
            continue;
        }
        
        vector<long long int> sf1(n), sf2(n);
        for(int i = n - 1; i >= 0; --i)
        {
            if(i == n - 1)
                sf1[i] = arr[i];
            else
                sf1[i] = max(arr[i], sf1[i + 1] + arr[i]);
            sf2[i] = (i == n - 1 ? sf1[i] : max(sf2[i + 1], sf1[i]));
        }
        
        long long int ans = -INF;
        for(int i = 0; i < n; ++i)
        {
            long long int left = (i > 0 ? pr1[i - 1] : -INF);
            long long int right = (i < n - 1 ? sf1[i + 1] : -INF);
            
            left = max(0LL, left);
            right = max(0LL, right);
            
            long long int best = -INF;
            if(i > 0)
                best = max(best, pr2[i - 1]);
            if(i < n - 1)
                best = max(best, sf2[i + 1]);
                
            for(int s : {-1, 1})
            {
                long long int curr = arr[i] + s * arr1[i] + left + right;
                ans = max({ans, best, curr});
            }
        }
        
        cout << ans << "\n";
    }
}