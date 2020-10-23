#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, W;
    long long ans = 0;
    cin >> n >> W;

    vector<bool> p(W + 1, false);  // constructed weight
    vector<int> w(n + 1, 0);       // item weight
    vector<long long> v(n + 1, 0); // item value
    vector<long long> V(W + 1, 0); // maximum value for constructed weight
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    p[0] = true;
    for (int k = 1; k <= n; k++) {
        for (int x = W; x >= 0; x--) {
            if (p[x] == true && x + w[k] <= W) {
                p[x + w[k]] = true;
                V[x + w[k]] = max(V[x + w[k]], V[x] + v[k]);
                ans = max(ans, V[x + w[k]]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
