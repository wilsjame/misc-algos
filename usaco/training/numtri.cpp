/*
ID: jgwilso1
PROG: numtri
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mxN = 1000;
int tri[mxN + 1][mxN + 1];
int dp[mxN + 1][mxN + 1];

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    int R, ans = 0;
    cin >> R;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j]; 
        }
    }
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= r; c++) {
            dp[r][c] = max(dp[r - 1][c - 1] + tri[r][c], dp[r - 1][c] + tri[r][c]);
        }
    }
    for (int c = 1; c <= R; c++) {
        ans = max(ans, dp[R][c]);
    }
    cout << ans << endl;
    return 0;
}
