#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int ans = 500005;
        for (int z = 0; z <= 100; z++) {
            int r = 0;
            for (int i = 0; i < N; i++) {
                if (A[i] != z) {
                    i += (K - 1);
                    r++;
                }
            }
            ans = min(ans, r);
        }
        cout << ans << endl;
    }

    return 0;
}
