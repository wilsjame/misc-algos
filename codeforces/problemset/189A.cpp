#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
    int a, b, c, x, y, z, n, ans = 0;;
    cin >> n >> a >> b >> c;
    for (x = 0; x <= 4000; x++ ) {
        for (y = 0; y <= 4000; y++) {
            int s = a * x + b * y;
            if (s == n) {
                ans = max(ans, x + y);
            }
            else if (s < n) {
                if ((n - s) % c == 0) {
                    z = (n - s) / c;
                    s += c * z;
                    assert(s == n);
                    ans = max(ans, x + y + z);
                }
            }
        }
    }
    cout << ans;

    return 0;
} 
// ax + bx + cz = n
// maximize x + y + z = n
