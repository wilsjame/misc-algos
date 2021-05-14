#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // L pos where array starts decreasing from beginning
    // R pos where array start increasing to the end
    int L = 0;
    int R = 0;
    for (int i = 1; i < n; i++) {
        int cur = a[i];
        int pre = a[i - 1];
        if (cur < pre) {
            L = i - 1;
            break;
        }

    }
    for (int i = n - 2; i >= 0; i--) {
        int cur = a[i];
        int pre = a[i + 1];
        if (cur > pre) {
            R = i + 1;
            break;
        }
    }
    reverse(a.begin() + L, a.begin() + R + 1);
    if (is_sorted(a.begin(), a.end())) {
        cout << "yes" << endl;
        cout << L + 1 << " " << R + 1 << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}
