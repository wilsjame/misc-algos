#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
const ll M =  1000000007;

int main() {
    ll n;
    cin >> n;
    ll a[2][2] = {};
    ll ans[2][2] = {};

    // identity matrix
    ans[0][0] = 1;
    ans[0][1] = 0;
    ans[1][0] = 0;
    ans[1][1] = 1;

    // seed N = 0 -> N = 1
    a[0][0] = 19;   // happy -> happy
    a[0][1] = 7;    // happy -> sad
    a[1][0] = 6;    // sad -> happy
    a[1][1] = 20;   // sad -> sad

    // matrix exponentiation O(log(n))
    while (n > 0) {
        if (n % 2) {
            // matrix multiply: ans = ans * a
            ll prod[2][2] = {};
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        prod[i][k] += ans[i][j] * a[j][k]; 
                        prod[i][k] %= M;
                    }
                }
            }
            copy(&prod[0][0], &prod[0][0] + 2 * 2, &ans[0][0]);
        }
        // matrix multiply: a = a * a
        ll prod[2][2] = {};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    prod[i][k] += a[i][j] * a[j][k];
                    prod[i][k] %= M;
                }
            }
        }
        copy(&prod[0][0], &prod[0][0] + 2 * 2, &a[0][0]);
        n /= 2;
    }

    cout << ans[0][0] << endl;

    return 0;
}
