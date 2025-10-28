#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int subtree_size[MAXN];
int N_nodes;

void dfs_size(int u, int p) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_size(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, k;
        if (!(cin >> n >> k)) return 0;
        N_nodes = n;

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            subtree_size[i] = 0;
        }

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            if (!(cin >> u >> v)) return 0;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs_size(1, 0);

        long long total_kawaiiness = 0;
        int threshold = n - k;

        for (int v = 1; v <= n; ++v) {
            long long roots_for_which_v_is_LCA = n;
            for (int u : adj[v]) {
                int component_size;
                if (subtree_size[u] < subtree_size[v] || v == 1)
                    component_size = subtree_size[u];
                else
                    component_size = n - subtree_size[v];
                if (component_size > threshold)
                    roots_for_which_v_is_LCA -= component_size;
            }
            total_kawaiiness += roots_for_which_v_is_LCA;
        }

        cout << total_kawaiiness << "\n";
    }

    return 0;
}
