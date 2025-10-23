#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randomInt(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll randomLong(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

void solve() {
    int numNodes;
    cin >> numNodes;

    vector<vector<int>> adjList(numNodes);
    for (int i = 0; i < numNodes - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> depth(numNodes), parent(numNodes), childCount(numNodes);

    auto dfs = [&](auto self, int currentNode, int parentNode) -> void {
        if (parentNode != -1) depth[currentNode] = depth[parentNode] + 1;
        parent[currentNode] = parentNode;

        for (int neighbor : adjList[currentNode]) {
            if (neighbor == parentNode) continue;
            self(self, neighbor, currentNode);
            childCount[currentNode]++;
        }
    };
    dfs(dfs, numNodes - 1, -1);

    array<vector<int>, 2> leavesByParity;
    for (int i = 0; i < numNodes; i++) {
        if (childCount[i] == 0)
            leavesByParity[depth[i] % 2].push_back(i);
    }

    vector<array<int, 2>> operations;
    int currentParity = depth[0] % 2;

    for (int i = 0; i < numNodes - 1; i++) {
        if (leavesByParity[currentParity ^ 1].empty()) {
            operations.push_back({1, -1});
            currentParity ^= 1;
        }

        int leafNode = leavesByParity[currentParity ^ 1].back();
        leavesByParity[currentParity ^ 1].pop_back();
        operations.push_back({2, leafNode});

        int parentNode = parent[leafNode];
        childCount[parentNode]--;
        if (childCount[parentNode] == 0)
            leavesByParity[depth[parentNode] % 2].push_back(parentNode);

        operations.push_back({1, -1});
        currentParity ^= 1;
    }

    cout << operations.size() << "\n";
    for (auto [opType, node] : operations) {
        if (opType == 1)
            cout << "1\n";
        else
            cout << "2 " << node + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testCases;
    cin >> testCases;
    while (testCases--) solve();
}
