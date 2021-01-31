#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, total = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    cerr << "total " << total << " total / 2 " << total / 2 << endl;
    sort(a.rbegin(), a.rend());

    int res = 0;
    for (int take = 0, i = 0; take <= total / 2; i++) {
        take += a[i];
        res++;
    }
    cout << res << endl;

    return 0;
}
