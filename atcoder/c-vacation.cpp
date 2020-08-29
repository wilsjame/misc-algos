#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;

    // dp[i][j] is the total cost such that we did activity j on day i
    int dp[n][3];
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    for (int i = 1; i < n; i++) {
        int c[3];
        for (int j = 0; j < 3; j++) cin >> c[j];
        for (int new_dp[3], j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) new_dp[k] = dp[i - 1][k];
            new_dp[j] = 0;
            dp[i][j] = c[j] + max({new_dp[0], new_dp[1], new_dp[2]});
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;

    return 0;
}
