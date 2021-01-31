#include <iostream>
using namespace std;
int main() {
    int t, l, r;
    cin >> t;

    while (t--) {
        cin >> l >> r;
        int x, y;
        x = l;
        y = 2 * x;

        if (y <= r) {
            cout << x << " " << y << endl;
        }
        else {
            cout << -1 << " " << -1 << endl;
        }
    }

    return 0;
}
