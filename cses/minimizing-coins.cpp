#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 5;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &c : coins)
        cin >> c;

    vector<int> dp(x + 1, INF); 
    dp[0] = 0; // the minimum number of coins to construct sum
    for (int sum = 1; sum <= x; sum++) {
        for (int c : coins) {
            if (sum - c >= 0) {
                dp[sum] = min(dp[sum], dp[sum - c] + 1);
            }
        }
    }
    dp[x] == INF ? cout << -1 : cout << dp[x];

    return 0;
}
