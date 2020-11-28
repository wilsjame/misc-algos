#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int A, B, ans = 0;
    cin >> A >> B;

    for (int i = A; i <= B; i++) {
        string z = to_string(i);
        string zr = z;
        reverse(zr.begin(), zr.end());
        ans += (z == zr);
    }

    cout << ans << endl;

    return 0;
}
