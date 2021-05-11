#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        
        ll l, r;
        l = 0, r = 0;
        ll mx, mn;
        mx = -1, mn = -1e10+5;
        ll ans = 0;

        while (r < n) {
            if (a[l] < 0 && a[r] >= 0) {
                ans += mn; 
                mn = -1e10+5;
                l = r;
            }
            else if (a[l] >= 0 && a[r] < 0) {
                ans += mx;
                mx = -1;
                l = r;
            }
            if (a[l] < 0) {
                mn = max(mn, a[r++]);
                if (r == n) {
                    ans += mn;
                }
            }
            else if (a[l] >= 0) {
                mx = max(mx, a[r++]);
                if (r == n) {
                    ans += mx;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
