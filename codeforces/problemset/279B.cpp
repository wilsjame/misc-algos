#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int l = 0, sum = 0, res = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (l <= r && sum > t) {
            sum -= a[l];
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout << res << endl;

    return 0;
}
