#include <iostream>
#include <cstdio>
using namespace std;
const int mxN = 300;
int g[mxN + 1][mxN + 1];
bool visited[mxN + 1][mxN + 1];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> g[i][j];
                visited[i][j] = false;
            }
        }
        // two pass O((r * c)^2)
        long long cnt = 0;
        for (int k = 0; k < r * c; k++) {
            // find max
            int mxX, mxY, mx = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (g[i][j] > mx && !visited[i][j]) {
                        mx = g[i][j];
                        mxX = i;
                        mxY = j;
                    }
                }
            }
            // update neighbors
            visited[mxX][mxY] = true;
            for (int d = 0; d < 4; d++) {
                    int nI = mxX + dx[d];
                    int nJ = mxY + dy[d];
                    if ((nI < 0 || nJ < 0) || (nI > r - 1) || nJ > c - 1) {
                        continue;
                    }
                    if (mx - g[nI][nJ] > 1) {
                        cnt += mx - g[nI][nJ] - 1; 
                        g[nI][nJ] = mx - 1;
                    }
            }
        }
        printf("Case #%d: %lld\n", tc, cnt);
    }
    return 0;
}
