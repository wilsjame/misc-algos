#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n);
    for (auto &a : A) 
        cin >> a;

    int ans = (int)1e4 + 5;
    for (int i = 0; i < n; i++) 
        if (A[i] <= k && A[i] != 0)
            ans = min(ans, abs(m - (i + 1)) * 10);
    cout << ans;

    return 0;
}
