#include <iostream>
using namespace std;
#define ll long long
const ll M = 1000000007;

void mul(ll a[2][2], ll b[2][2]) {
    ll ans[2][2] = {};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ans[i][k] += (a[i][j] % M * b[j][k] % M) % M;
                ans[i][k] %= M;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = ans[i][j];
        }
    }
}

int main() {
    ll n;
    cin >> n;
    ll f0, f1;
    f0 = 0;
    f1 = 1;
    // recurrence 
    ll z[2][2] = {{1, 1}, {1, 0}};
    // identity
    ll res[2][2] = {{1, 0}, {0, 1}};
    // matrix binpow O(2^3 * log(n))
    while (n > 0) {
        if (n % 2) {
            mul(res, z);
        }
        mul(z, z);
        n /= 2;
    }

    ll ans;
    ans = f1 * res[1][0] + f0 * res[1][1];
    cout << ans << endl;

    return 0;
}
