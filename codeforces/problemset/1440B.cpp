#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N * K);
        for (auto &a : A) 
            cin >> a;

        // work backwards
        ll ans = 0;
        for (int pos = A.size() - N, i = 0; i < K; i++, pos -= N) {
            //cerr << "pos start " << A[pos] << endl;
            //cerr << "pos mid " << A[(pos + (N + 2 - 1) / 2) - 1] << endl;
            ans += A[(pos + (N + 2 - 1) / 2) - 1];
            pos = (pos + (N + 2 - 1) / 2) - 1; 
        }
        cout << ans << endl;

    }
	return 0;
}

