#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    ll N, M, ans;
    cin >> N >> M;
    
    if (N > M) {
        swap(N, M);
    }

    if (N == 1 && M == 1) {
        ans = 1;
    }
    else if (N == 1) {
        ans = M - 2;
    }
    else {
        ans = (N - 2) * (M - 2);
    }

    cout << ans << endl;

    return 0;
}
