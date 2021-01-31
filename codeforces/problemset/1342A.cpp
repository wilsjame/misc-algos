#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    int T;
    cin >> T;
    while(T--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;

        ll  ans;
        if (2 * a < b) {
            ans = a * (x + y);
        }
        else {
            ans = b * min(x, y);
            ans += a * (max(x, y) - min(x, y));
        }
        cout << ans << endl;
    }
    return 0;
}
