#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g[100000+5];
int dp[100000+5]; // dp[i] longest path from node i

int dfs(int i) {
    if (dp[i] > 0) return dp[i];
    // process node i
    for (auto j: g[i]) {
        dp[i] = max(dp[i], dfs(j) + 1);
    }
    return dp[i];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int node, neighbor;
        cin >> node >> neighbor;
        g[node].push_back(neighbor);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;

    return 0;
}
