#include <iostream>
using namespace std;
#define ll long long
const ll M = 1000000007;

void mul(ll a[2][2], ll b[2][2]) {
    ll res[2][2] = {};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][k] += ((a[i][j] % M) * (b[j][k] % M)) % M;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = res[i][j];
        }
    }
}

int main() {
    ll A, B, n, x;
    cin >> A >> B >> n >> x;

    /* recurrence X basis = v
     * [ A B ]   [ x ]   [ gn ]
     * [ 0 1 ] X [ 1 ] = [ 1  ]
     */
    ll z[2][2] = {{A, B}, {0, 1}};
    ll res[2][2] = {{1, 0}, {0, 1}}; // identity matrix

    // binpow O((matrix size)^3 * log(n))
    while (n > 0) {
        if (n % 2) {
            mul(res, z);
        }
        mul(z, z);
        n /= 2;
    }

    A = res[0][0];
    B = res[0][1];
    ll ans = ((A * x) % M + B) % M;
    cout << ans << endl;

    return 0;
}
