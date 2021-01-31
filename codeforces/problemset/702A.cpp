#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, cur, ans;
    cin >> n;
    int a[n];

    cur = 1, ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            continue;
        }
        else if (a[i] > a[i - 1]) {
            cur++;
            ans = max(cur, ans);
        }
        else {
            cur = 1;
        }
    }
    cout << ans << endl;

    return 0;
}
