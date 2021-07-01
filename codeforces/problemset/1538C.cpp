#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << endl;
        int n, l , r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            // binary search first pos where value is atleast a[i] + a[lp] 
            // binary search last pos where value is at most a[i] + a[rp]
            int lp = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin();
            int rp = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin() - 1;
            if (a[i] + a[lp] >= l && a[i] + a[rp] <= r) {
                ans += rp - lp + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
