#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
const int INF = 1e9 + 5;
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto &x : h) {
        cin >> x;
    }

    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= i + k; j++) {
            if (j < n) {
                dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
            }
        } 
    }
    cout << dp[n - 1] << endl;

    return 0;
}

