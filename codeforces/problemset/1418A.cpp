#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        // need to perform second trade k times to get enough coals
        // so trades += k
        // now how many total sticks do we need?
        // need k coals and k sticks
        // ky sticks for coals
        // k sticks additionally to pair with the coals 
        // so ky + k sticks total
        // we initially have one stick!
        // so we actually need ky + k - 1 sticks
        // how many trades to get this many sticks
        // x - 1 stick per trade
        // ceiling (total / trade amount)
        // ceil(ky + k - 1 / x - 1)
        // ceil(a/b) = floor(a + b - 1 / b)
        // ky + k + x - 1 - 1 - 1 / x - 1
        cout << k + ((k*y+k+x-3)/(x-1)) << endl;
    }
    return 0;
}
