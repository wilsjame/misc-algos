#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MX = 500005;
vector<int> adj[MX];
vector<int> path_taken;
int visits_a[MX]; // dp
int visits_b[MX]; // dp

void dfsA(int u, int a) {
    path_taken.push_back(u);
    for (auto v : adj[u]) {
        dfsA(v, a);
    }
    visits_a[u]++;
    int n = path_taken.size();
    if (n - a - 1 >= 0) {
        visits_a[path_taken[n - a - 1]] += visits_a[u];
    }
    path_taken.pop_back();
}

void dfsB(int u, int b) {
    path_taken.push_back(u);
    for (auto v : adj[u]) {
        dfsB(v, b);
    }
    visits_b[u]++;
    int n = path_taken.size();
    if (n - b - 1 >= 0) {
        visits_b[path_taken[n - b - 1]] += visits_b[u];
    }
    path_taken.pop_back();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visits_a[i] = 0;
            visits_b[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u;
            cin >> u;
            adj[u].push_back(i + 1);
        }
        // dp dfs tree traversal
        path_taken.clear();
        dfsA(1, a);
        path_taken.clear();
        dfsB(1, b);
        // inclusion exclusion P(AUB) = P(A) + P(B) - P(A intersection B)
        // mutually independent P(A intersect B) = P(A)P(B|A) = P(A) * P(B) 
        double ans = 0;
        for (int i = 1; i <= n; i++) {
            double pa = (double)visits_a[i] / n;
            double pb = (double)visits_b[i] / n;
            ans += pa + pb - pa * pb;
        }
        printf("Case #%d: %.6f\n", t, ans);
    }
    return 0;
}
