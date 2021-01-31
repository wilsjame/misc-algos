#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 1e6 + 5;
int main() {
    int n, m, ans = 0;
    cin >> n;
    vector<int> boy(n);
    for (auto &x : boy) {
        cin >> x;
    }
    cin >> m;
    vector<int> girl(m);
    for (auto &x : girl) {
        cin >> x;
    }
    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());
    // O(mn)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(boy[i] - girl[j]) < 2) {
                girl[j] = INF;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
