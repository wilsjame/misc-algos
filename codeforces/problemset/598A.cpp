#include <iostream>
using namespace std;
int main() {
    long long t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        long long ans;

        // sum of n natural numbers
        ans = (n * (n + 1)) / 2;

        long long a = 1;
        while (a <= n) {
            a *= 2;
            //cerr << a << endl;
            ans -= a;
        }
        cout << ans << endl;
    }

    return 0;
}
