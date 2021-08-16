#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ok(int k, int n, vector<int> a, vector<int> b) {
    int N = n + k;
    vector<int> curA(N, 100), curB(N, 0);
    for (int i = 0; i < n; i++) {
        curA[i] = a[i];
        curB[i] = b[i];
    }
    sort(curA.rbegin(), curA.rend());
    sort(curB.rbegin(), curB.rend());
    int rem = 0;
    for (int i = 0; i < N - N / 4; i++) {
        rem += curA[i] - curB[i];
    }
    return rem >= 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n; 
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        // binary search on k added stages
        // ok monotonically increasing ex) false -> true: !ok(k), ..., ok(k+n)
        // find smallest k that holds true
        int l = 0, r = n; 
        while (l < r) {
            int m = (l + r) / 2;
            if (ok(m, n, a, b)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}
