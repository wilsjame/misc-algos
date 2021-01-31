#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        long long x;
        cin >> x;

        // nice stair levels n: 1, 3, 7, ... 2^n-1
        // cells used for each level n: n(n+1) / 2
        // use cells up to x
        long long n = 1, h, cells;
        // 1 * 2^n - 1
        h = (1 << n) - 1; 
        cells = (h * (h + 1)) / 2;
        while (cells <= x) {
            h = (1 << ++n) - 1;
            cells += (h * (h + 1)) / 2;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
