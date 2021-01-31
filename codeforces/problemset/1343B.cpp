#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        // one side's sum will be even and
        // the other side's sum will be odd
        // if not a multiple of 4
        if (n % 4 != 0) {
            cout << "NO" << endl;
        }
        else { // both side's sums are even
            // even
            for (int k = 1, i = 0; i < (n / 2); i++, k++) {
                a[i] = 2 * k;
            }
            // odd
            for (int k = 0, i = n / 2; i < n; i++, k++) {
                a[i] = 2 * k + 1;
            }
            // adjust last number 
            a[n - 1] += n / 2;

            cout << "YES" << endl;
            for (auto v : a) cout << v << " ";
            cout << endl;
        }
    }

    return 0;
}
