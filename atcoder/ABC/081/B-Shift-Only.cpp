#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, ans = 33;
    cin >> N;
    vector<int> A(N);
    for (auto &k : A) cin >> k;

    for (int i = 0; i < N; i++) {
        int n = 0;
        while (A[i] > 0 && (A[i] & 1) == 0) {
            A[i] = A[i]>>1;
            ans = min(ans, ++n);
        }
    }

    cout << ans << endl;

    return 0;
}
