/*
ID: jgwilso1
PROG: castle
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int mxN = 50;
vector<pair<int, int>> g[mxN+1][mxN+1];
bool visited[mxN+1][mxN+1];
int component[mxN+1][mxN+1], sz[mxN*mxN+1];;
int mxsingle, mxdouble, mxi, mxj, m, n, c;
char dir;

void dfs(int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = true;
    if (component[i][j] == 0) {
        component[i][j] = c;
        sz[c]++;
    }
    for (auto u : g[i][j]) {
        int ii = u.first;
        int jj = u.second;
        dfs(ii, jj);
    }
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    cin >> m >> n;
    // build graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int k;
            cin >> k;
            // unpack walls
            if (k/8) k -= 8;
            else g[i][j].push_back({i+1, j}); // S open
            if (k/4) k -= 4;
            else g[i][j].push_back({i, j+1}); // E open
            if (k/2) k -= 2;
            else g[i][j].push_back({i-1, j}); // N open
            if (k/1) k -= 1;
            else g[i][j].push_back({i, j-1}); // W open
        }
    }
    // flood fill components (rooms)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j]) {
                c++;
                dfs(i, j);
            }
        }
    }
    // largest single room
    for (int i = 1; i <= c; i++) {
        mxsingle = max(mxsingle, sz[i]);
    }
    // largest double room
    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; --i) {
            // N first
            if (component[i][j] != component[i-1][j]) {
                if (sz[component[i][j]]+sz[component[i-1][j]] > mxdouble) {
                    mxdouble = sz[component[i][j]]+sz[component[i-1][j]];
                    mxi = i;
                    mxj = j;
                    dir = 'N';
                }
            }
            // E 
            if (component[i][j] != component[i][j+1]) {
                if (sz[component[i][j]]+sz[component[i][j+1]] > mxdouble) {
                    mxdouble = sz[component[i][j]]+sz[component[i][j+1]];
                    mxi = i;
                    mxj = j;
                    dir = 'E';
                }
            }
        }
    }
    cout << c << endl;
    cout << mxsingle << endl;
    cout << mxdouble << endl;
    cout << mxi << " " << mxj << " " << dir << endl;
    return 0;
}
