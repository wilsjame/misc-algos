#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (auto &x : c) {
            cin >> x;
        }

        ll ans = 1e18;
        ll mnO = 1e9 + 5;
        ll mnE = 1e9 + 5;
        ll sumO = 0;
        ll sumE = 0;
        for (int i = 1; i <= n; i++) {
            ll cost = c[i - 1];
            if (i % 2) {
                sumO += cost;
                if (cost < mnO) {
                    mnO = cost;
                }
            }
            else {
                sumE += cost;
                if (cost < mnE) {
                    mnE = cost;
                }
            }
            ll cntO = (i + 2 - 1) / 2;
            ll cntE = i / 2;
            ans = min(ans, sumO + (n - cntO) * mnO + sumE + (n - cntE) * mnE);
        }
        cout << ans << endl;
    }
    return 0; 
}
