#include <iostream>
#include <vector>
using namespace std;

long long dp[55][55][2505];

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> X(N + 1);
    for (int i = 1; i <= N; i++) 
        cin >> X[i];

    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k + X[i + 1] <= 2500; k++) {
                // update state from previous
                dp[i + 1][j][k] += dp[i][j][k];
                // update state with card value
                dp[i + 1][j + 1][k + X[i + 1]] += dp[i][j][k];
            }
        }
    }

    long long ans = 0;
    for (int t = 1; t <= N; t++) {
        ans += dp[N][t][A * t];
    }
    cout << ans;

    return 0;
}
// dp[i][j][k] is the number of ways to
// use j cards from the first i cards
// to make sum k. When dp is filled (ie i = N)
// add all the j states from t = 1 to N
// and the sum the (A)verage * t to find the total
// number of ways A can be created 
// O(N^2 * N^2) x_x
