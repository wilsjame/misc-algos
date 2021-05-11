#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int sgn(int x) { return x < 0 ? -1 : 1; }
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        ll l = a[0];
        for (int i = 1; i < n; i++) {
            ll r = a[i];
            if (sgn(l) == sgn(r)) {
                l = max(l, r);
            }
            else {
                ans += l;
                l = r;
            }
        }
        cout << ans + l << endl;
    }
    return 0;
}
