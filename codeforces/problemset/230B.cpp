#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    vector<int> sieve(1000000, 0);
    sieve[0] = sieve[1] = 1;
    for (int x = 2; x <= 1000000; x++) {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= 1000000; u += x) {
            sieve[u] = x;
        }
    }

    // numbers with only 3 divisors 
    // are prime numbers squared
    for (auto n : a) {
        long long k = sqrt(n);
        if (k*k == n && !sieve[k])
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }

    return 0;
}
