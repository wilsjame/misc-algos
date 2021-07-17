#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int sums[51][31];
int dp[51][1501];

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, K, P;
        cin >> N >> K >> P;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                cin >> sums[i][j];
                sums[i][j] += sums[i][j - 1];
            }
        }

        // dp[i][j] max beauty picking j plates from the first i stacks
        // O(N * P * K)
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= P; j++) {
                dp[i][j] = 0;
                for (int k = 0; k <= min(j, K); k++) {
                    dp[i][j] = max(dp[i][j], sums[i][k] + dp[i-1][j - k]);
                }
            }
        }
        printf("Case #%d: %d\n", t, dp[N][P]);
    }

    return 0;
}
