#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ans = 1;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int worker = a[i], depth = 1;
        while (worker > 0) {
            worker = a[worker];
            ans = max(ans, ++depth);
        }
    }
    cout << ans << endl;
    
    return 0;
}
