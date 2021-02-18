#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.rbegin(), a.rend());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (m <= 0) break;
        m -= a[i];
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}
