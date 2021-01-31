#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, b[200001], ans;
    fill(b, b + 200001, 0);
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    for (int i = n - 1 ; i >= 0; --i) {
        if (b[a[i]] == 1) {
            b[a[i]] = 0;
            ans = a[i];
        }
    }
    cout << ans << endl;

    return 0;
}
