/*
ID: jgwilso1
PROG: money
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int mxC = 25, mxN = 10000;
long long dp[mxC + 1][mxN + 105];

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int C, N;
    cin >> C >> N;
    vector<int> coin = {0};
    for (int i = 0; i < C; i++) {
      int c; 
      cin >> c;
      coin.push_back(c);
    }
    // O(C*N*N)
    dp[0][0] = 1; // dp[i][j] is ways to make value j using any amount of the first i coins
    for (int i = 1; i <= C; i++) {
      dp[i][0] = 1;
      for (int j = 1; j <= N; j++) {
        for (int k = j; k >= 0; k -= coin[i]) {
          dp[i][j] += dp[i - 1][k];
        }
      }
    }
    cout << dp[C][N] << endl;

    return 0;
}
