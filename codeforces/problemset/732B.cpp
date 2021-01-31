#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
    int n, k, w = 0;
    cin >> n >> k;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = 0;
    }

    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i - 1] + a[i] < k) {
            w += k - (a[i - 1] + a[i]);
            a[i] += k - (a[i - 1] + a[i]);
        }
        b[i] = a[i];
    }
    cout << w << endl;
    for (auto x : b) {
        cout << x << " ";
    } cout << endl;

    return 0;
}
