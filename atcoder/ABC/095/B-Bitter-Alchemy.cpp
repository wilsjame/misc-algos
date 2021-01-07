#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (auto &a : A)
        cin >> a;

    int minv = 1000 + 5, ans = 0;
    for (auto k : A) {
        X -= k;
        minv = min(minv, k);
        ans++;
    }
    ans += X / minv;
    cout << ans;
    
    return 0;
}
