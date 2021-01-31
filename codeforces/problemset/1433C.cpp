#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        int mx = -1, pos;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            if (A[i] > mx) {
                mx = A[i];
                pos = i;
            }
        }
        int ans = -1;
        if (pos == 0) {
            //cerr << "trace1 ";
            for (int i = pos + 1; i < N; i++) {
                if (mx > A[i]) {
                    ans = i;
                    break;
                }
            }
        }
        else if (pos == N - 1) {
            for (int i = pos - 1; i >= 0; i--) {
                if (mx > A[i]) {
                    ans = i + 2;
                    break;
                }
            }
        }
        else {
            for (int i = pos + 1; i < N; i++) {
                if (mx > A[i]) {
                    ans = i;
                    break;
                }
            }
            for (int i = pos - 1; i >= 0; i--) {
                if (mx > A[i]) {
                    ans = i + 2;
                    break;
                }
            }
        }

        cout << ans << endl;
    }


    return 0;
}
