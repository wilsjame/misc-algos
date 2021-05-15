#include <iostream>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    int fedor;
    cin >> fedor;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int p = 0; p < n; p++) {
            cnt += ((fedor >> p) & 1) ^ ((a[i] >> p) & 1);
        }
        ans += cnt <= k;
    }
    cout << ans << endl;

    return 0;
}
