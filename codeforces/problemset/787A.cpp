#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = -1;
    for (int i = 0; i <= max({a, b, c, d,}) && ans < 0; i++) {
        for (int j = 0; j <= max({a, b, c, d}) && ans < 0; j++) {
            if (a * i + b == c * j + d) {
                ans = a * i + b; // then break;
            }
        }
    }
    cout << ans;

    /*
    while (b != d && b < a * c) {
        if (b < d)
            b += a;
        else
            d += c;
    }
    //cerr << "b " << b << " d " << d << endl;
    cout << (b==d ? b : -1);
    */

    return 0;
}
