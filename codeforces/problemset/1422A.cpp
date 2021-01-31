#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c;
        // floor
        d = sqrt(a * a + (b + c) * (b + c));
        cout << d << endl;
    }

    return 0;
}
