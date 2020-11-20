#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {

    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (auto &v : A) cin >> v;
    for (auto &v : B) cin >> v;
    for (auto &v : C) cin >> v;

    // total ways to make A < B < C 
    // sort A and C, iterate B, binary search A and C
    // O(NlogN + N + logN)

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    ll total = 0;
    for (int i = 0; i < N; i++) {
        int l = 0, r = N - 1, ans = -1, ans2 = N;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] < B[i]) {
                ans = mid;
                l = mid + 1;
            }
            else { 
                r = mid - 1;
            }
        }

        l = 0, r = N - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (C[mid] > B[i]) {
                ans2 = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        total += 1ll * (ans + 1) * (N - ans2);
    }

    cout << total << endl;

    return 0;
}
//TODO refactor using C++ functions lower_bound and upper_bound!
