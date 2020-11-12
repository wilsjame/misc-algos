#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[200005];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // brute force? xD
    vector<int> hop;
    for (auto u : adj[1]) {
        if (u == N) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
        hop.push_back(u);
    }
    for (auto u : hop) {
        for (auto s : adj[u]) {
            if (s == N) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}
