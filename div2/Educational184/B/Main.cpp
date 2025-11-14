#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            if(s[i] == '<'){
                if(i-1 >= 0){
                    adj[i].push_back(i-1);
                    indeg[i-1]++;
                }
            } else if(s[i] == '>'){
                if(i+1 < n){
                    adj[i].push_back(i+1);
                    indeg[i+1]++;
                }
            } else {
                if(i-1 >= 0){
                    adj[i].push_back(i-1);
                    indeg[i-1]++;
                }
                if(i+1 < n){
                    adj[i].push_back(i+1);
                    indeg[i+1]++;
                }
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++) if(indeg[i] == 0) q.push(i);
        vector<int> topo;
        topo.reserve(n);
        while(!q.empty()){
            int u = q.front(); q.pop();
            topo.push_back(u);
            for(int v: adj[u]){
                if(--indeg[v] == 0) q.push(v);
            }
        }

        if((int)topo.size() < n) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> dp(n, 0);
        for(int idx = n-1; idx >= 0; --idx){
            int u = topo[idx];
            int best = 0;
            for(int v: adj[u]) best = max(best, dp[v]);
            dp[u] = 1 + best; 
        }

        int ans = 0;
        for(int x: dp) ans = max(ans, x);
        cout << ans << '\n';
    }
    return 0;
}
