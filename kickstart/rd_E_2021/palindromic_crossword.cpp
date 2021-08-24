#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
const int mxN = 1e3; 
char g[mxN + 1][mxN + 1];
int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        cin >> n >> m;
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
                if (g[i][j] != '#' && g[i][j] != '.') {
                    q.push({i, j});
                }
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // find black squares left and right of letter
            int lp, rp; // row (left, right)
            for (lp = y - 1;; lp--)
                if (lp == 0 || g[x][lp] == '#') 
                    break;
            for (rp = y + 1;; rp++) 
                if (rp == m + 1 || g[x][rp] == '#') 
                    break;
            // letter is y - lp from left black square
            // target is then y - lp from right black square
            int tar = rp - (y - lp);
            if (g[x][tar] == '.') {
                g[x][tar] = g[x][y];
                q.push({x, tar});
                cnt++;
            }
            // find black squares above and below letter
            int tp, bp; // col (top, bottom)
            for (tp = x - 1;; tp--)
                if (tp == 0 || g[tp][y] == '#')
                    break;
            for (bp = x + 1;; bp++) 
                if (bp == n + 1 || g[bp][y] == '#')
                    break;
            // letter is x - tp from top black square
            // target is then x - tp from bottom black square
            tar = bp - (x - tp);
            if (g[tar][y] == '.') {
                g[tar][y] = g[x][y];
                q.push({tar, y});
                cnt++;
            }
        }
        printf("Case #%d: %d\n", tc, cnt);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

// store crossword in graph g
// BFS (DFS would work also) and
//  for every letter determine its location relative to its nearest black squares
//  do this both row and column wise
//  row ex) . # . . # . A . . . # . .
//  A is 2 from the start so we must place an A 2 from the back
//  row ex) . # . . # . A . A . # . .
//  col ex) same as row example but vertical!
//  remember to push added letter to bfs queue
//  BFS O(N + M) visits every square once
