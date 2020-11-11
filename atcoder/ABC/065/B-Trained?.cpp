#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100005];
bool visited[100005];
int steps = 0;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;

    if (s == 2) return;
    steps++;

    for (auto u: adj[s]) {
        dfs(u);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        adj[i].push_back(n);
    }

    dfs(1);
    cout << (visited[2] ? steps : -1) << endl;

    return 0;
}
