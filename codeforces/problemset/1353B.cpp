#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, sum = 0;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto &v : a) cin >> v;
        for (auto &v : b) cin >> v;

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        for (int i = 0; i < k && a[i] < b[i]; i++) {
            a[i] = b[i];
        }

        for (auto k : a) {
            sum += k;
        }
        cout << sum << endl;
    }

    return 0;
}
