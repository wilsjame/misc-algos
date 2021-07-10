#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> c(n);
        vector<ll> a(n);
        vector<ll> b(n);
        for (auto &k : c) cin >> k;
        for (auto &k : a) cin >> k;
        for (auto &k : b) cin >> k;

        // longest simple cycle ending on chain i
        vector<ll> dp(n + 1, 0);
        dp[1] = abs(a[1] - b[1]) + (c[1] - 1) + 2; // c[i] + 1
        for (int i = 2; i < n; i++) {
            if (a[i] == b[i]) {
                dp[i] = c[i] + 1;
            }
            else {
                dp[i] = max(abs(a[i] - b[i]) + c[i] + 1, dp[i - 1] - abs(a[i] - b[i]) + c[i] + 1); 
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}
