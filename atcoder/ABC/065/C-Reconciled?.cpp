#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

int main() {
    ll N, M, ans = 1;
    cin >> N >> M;

    if (N == M) {
        // (N! * M!) * 2
        for (ll i = 1; i <= N; i++, ans %= mod)
            ans *= i;
        for (ll i = 1; i <= M; i++, ans %= mod)
            ans *= i;
        ans *= 2;
    }
    else if (abs(N - M) == 1) {
        // N! * M!
        for (ll i = 1; i <= N; i++, ans %= mod) 
            ans *= i;
        for (ll i = 1; i <= M; i++, ans %= mod) 
            ans *= i;
    }
    else {
        ans = 0;
    }

    cout << ans % mod << endl; 

    return 0;
}
