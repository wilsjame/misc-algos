#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;
        // Sum of first k odd numbers is k^2.
        // We have a sum n and sum of k (distinct) odd numbers,
        // sum of an odd amount of odd numbers is odd so n must be odd
        // sum of an even number of odd numbers is even so n must be even
        cout << (k*k > n || n%2 != k%2 ? "NO" : "YES") << endl;
    }
    return 0;
}
