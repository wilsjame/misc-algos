#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;

    for (int p, q, i = 0; i < n; i++) {
        cin >> p >> q;
        if (q - p >= 2) ans++;
    }
    cout << ans << endl;

    return 0;
}
