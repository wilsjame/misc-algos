#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int n, l = 1, ans = 1;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) continue;
        if (a[i] >= a[i - 1]) {
            ans = max(ans, ++l);
        }
        else {
            l = 1;
        }
    }
    cout << ans << endl;

    return 0;
}

