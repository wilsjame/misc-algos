#include <iostream>
using namespace std;

#define ll long long
const ll M = 1000000007;

int main() {
    ll n;
    cin >> n;
    
    /*
    ll a, b, c;
    a = 0, b = 1;
    for (int i = 0; i < n - 1; i++) {
        int new_a = 0 * a + 1 * b;
        int new_b = 1 * a + 1 * b;
        a = new_a;
        b = new_b;
    }
    */

    ll ans[2][2] = {{1, 0}, {0, 1}}; // identity matrix
    ll a[2][2]= {{0, 1}, {1, 1}};

    // binpow matrix O((2 states)^3 * log(n))
    while (n > 0) {
        if (n % 2) {
            // mat mult: ans = ans * a
            ll p[2][2] = {};
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        p[i][k] += ans[i][j] % M * a[j][k] % M;
                        p[i][k] %= M;
                    }
                }
            }
            copy(&p[0][0], &p[0][0] + 2 * 2, &ans[0][0]);
        }
        // mat mult: a = a * a
        ll p[2][2] = {};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    p[i][k] += a[i][j] % M * a[j][k] % M;
                    p[i][k] %= M;
                }
            }
        }
        copy(&p[0][0], &p[0][0] + 2 * 2, &a[0][0]);
        n /= 2;
    }

    cout << ans[1][0] << endl;

    return 0;
}
