#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a = 0, b = 0, n;
        cin >> n;

        a += pow(2, n);
        for (int i = 1; i <= ((n/2) -1); i++) {
            a += pow(2, i);
        }
        for (int i = (n/2); i <= n - 1; i++) {
            b += pow(2, i);
        }

        cout << abs(a - b) << endl;

    }
    return 0;
}
