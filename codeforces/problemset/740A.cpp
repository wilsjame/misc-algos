#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

const ll INF = 1e9 + 5;

int main() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;

    ll ans = INF;

    if (N % 4 == 0)
        ans = 0;
    if ((N + 1) % 4 == 0) {
        ans = min({ans, A, B + C, 3 * C});
    }
    if ((N + 2) % 4 == 0) {
        ans = min({ans, 2 * A, B, 2 * C});
    }
    if ((N + 3) % 4 == 0) {
        ans = min({ans, 3 * A, A + B, C});
    }
    cout << ans;

    return 0;
}
