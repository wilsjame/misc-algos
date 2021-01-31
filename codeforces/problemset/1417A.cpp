#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &k : a) cin >> k;
        sort(a.begin(), a.end());
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            int diff = k - a[i];
            cnt += diff / a[0];
        }
        cout << cnt << endl;
    }

    return 0;
}
