#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;
int n;
vector<int> tree[N];
int a[N];  // cats
int dp[N]; // cats in a row
bool visited[N];
int m;
int ans = 0;

void read() {
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    return;
}

void dfs(int v) {
    visited[v] = true;
    if (dp[v] > m) return;
    int cnt = 0; // use to tell if we're on a leaf node
    for (int u : tree[v]) {
        if (visited[u]) continue;
        cnt++;
        if (a[u]) {
            dp[u] = dp[v] + 1;
        }
        dfs(u);
    }
    if (cnt == 0) ans++;
    return;
}

int main() {
    read();
    dp[1] = a[1];
    dfs(1);
    cout << ans << endl;
    return 0;
}
